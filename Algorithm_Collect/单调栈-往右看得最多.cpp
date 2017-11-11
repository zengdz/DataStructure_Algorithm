/* 2017/11/11 @DGUT
 * 有一群牛站成一排，每头牛都是面朝右的，每头牛可以看到他右边身高比他小的牛
 * 给出每头牛的身高，要求每头牛能看到的牛的总数
 * 示例：输入 [5 3 1 2 4]，输出 [4 2 0 0 0]
 * 本质就是找右边第一个更大值
 */
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <limits.h>

using namespace std;

// 生成随机数组:随机数的范围[0,range-1]
void GenerateRandomVec(vector<int> &arr, int range) {
	srand(unsigned(time(0)));
	for(int i = 0; i < arr.size(); ++i)
		arr[i] = rand() % range;
}

vector<int> FindMostFromRight(vector<int>& arr) {
	vector<int> ret(arr.size());
	stack<int> monoStack;
	// 追加一个极大值，把所有元素出栈，注意arr.size也随之改变 
	arr.push_back(INT_MAX); 
	for(int i = 0; i < arr.size(); ++i) {
		while(!monoStack.empty() && arr[monoStack.top()] < arr[i]) {
			int height = monoStack.top();
			// 只往右看找第一个更大的就是所能看到的边界 
			ret[height] = i - height - 1;
			monoStack.pop();
		}
		monoStack.push(i);
	}
	return ret;
}

void PrintArrayResult(const string info, vector<int>& arr) {
	cout << info << endl;
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int num;
	cout << "input number of random integer: ";
	cin >> num;
	vector<int> arr(num);
	GenerateRandomVec(arr, 20);
	PrintArrayResult("random vector:", arr);
	
	vector<int> ans;
	ans = FindMostFromRight(arr);
	PrintArrayResult("result vector:", ans);
	
	return 0;
}

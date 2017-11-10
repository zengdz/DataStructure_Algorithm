/* 2017/11/7-2017/11/10 @SCUT-DGUT
 * 算法看不懂的时候，需要实际一步步去跑才能理解 
 * 给出一个柱形图(histogram), 它的每个项目的宽度是1，高度由数组给出 
 * 求出在这个柱形图中的最大面积的长方形。比如 2 1 4
 * 分别能获得的最大面积为 2 3 4，所以最大为 4 
 * 如果不使用单调栈，可以使用预处理数组，分别生成左边界和右边界数组
 */
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// 生成随机数组:随机数的范围[0,range-1]
void GenerateRandomVec(vector<int> &arr, int range) {
	srand(unsigned(time(0)));
	for(int i = 0; i < arr.size(); ++i)
		arr[i] = rand() % range;
}

int maxHistogramArea(vector<int>& arr) {
	int ret = 0;
	arr.push_back(0); // 在末尾追加0，最后把全部元素出栈 
	stack<int> monoStack; 
	for(int i = 0; i < arr.size(); ++i) {
		// 注意维持的是单调递增，递减或者相等都要进行处理
		while(!monoStack.empty() && arr[monoStack.top()] >= arr[i]) {
			// 当前弹出的高度值要保存，因为弹出后栈顶就发生变化
			int height = arr[monoStack.top()];
			monoStack.pop();
			// 诀窍在于把当前栈顶弹出后，下一个栈顶就是左边的边界
			// 当左边界为空时，将其索引设为-1 
			int idx = monoStack.empty() ? -1 : monoStack.top();
			// i是右边界，idx是左边界，夹在中间的是宽度 width=i-idx-1
			ret = max(ret, height * (i - idx - 1));
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
	
	cout << maxHistogramArea(arr) << endl;
	
	return 0;
}

/* 2017/11/6 @SCUT
 * 给定一个数组，返回一个大小相同的数组。返回的数组的第i个位置的值应当是，对于原数组中的第i个元素，
 * 至少往右走多少步，才能遇到一个比自己大的元素，返回该步数 
 * 如果之后没有比自己大的元素，或者已经是最后一个元素，则返回-1
 * 示例：输入 [5 3 1 2 4]，输出 [-1 3 1 1 -1]
 */
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// 生成随机数组 
void RandomVec(vector<int> &arr) {
	srand(unsigned(time(0)));
	for(int i = 0; i < arr.size(); ++i)
		arr[i] = rand() % 100; // 随机数的范围[0,99]
}

vector<int> nextExceed(vector<int>& arr) {
	vector<int> ret(arr.size(), -1); // 初值-1 
	stack<int> monoStack; // 使用栈结构 
	for(int i = 0; i < arr.size(); ++i) {
		// 当栈不为空且栈顶元素小于新入栈元素，说明遇到第一个更大的
		// 则需要计算栈顶元素到第一个更大元素的步数，并弹出栈顶元素 
		// while循环保证：栈顶如果小于新元素会一直弹出直到满足单调 
		while(!monoStack.empty() && arr[monoStack.top()] < arr[i]) {
			ret[monoStack.top()] = i - monoStack.top();
			monoStack.pop();
		}
		monoStack.push(i); // 栈中保存的是索引不是元素值 
	}
	// 最后栈中元素单调递减，其位置都返回-1 
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
	RandomVec(arr);
	PrintArrayResult("random vector:", arr);
	
	vector<int> ans(num);
	ans = nextExceed(arr);
	
	PrintArrayResult("result vector:", ans);
	
	return 0;
}

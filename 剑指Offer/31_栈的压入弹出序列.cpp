/*
 * 给出一个栈的压入序列，和一个弹出序列，判断该弹出序列是否存在
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
		return false;
	stack<int> s;
	int j = 0;
	// 把压入序列依次压入辅助栈
	// 如果栈顶和弹出序列相同则依次弹出
	// 若弹出序列正确，则辅助栈所有元素会弹出，栈变为空
	for (int i = 0; i < pushV.size(); ++i) {
		s.push(pushV[i]);
		// 如果辅助栈不为空，且栈顶和弹出序列相等则弹出
		while (!s.empty() && s.top() == popV[j]) {
			s.pop();
			++j; // 更新弹出序列索引
		}
	}
	// 根据辅助栈是否为空判断True还是False
	return s.empty();
}

int main()
{
	vector<int> Push = { 1,2,3,4,5 };
	vector<int> Pop1 = { 4,5,3,2,1 }; // True
	vector<int> Pop2 = { 4,3,5,1,2 }; // False

	cout << IsPopOrder(Push, Pop1) << endl;
	cout << IsPopOrder(Push, Pop2) << endl;

	return 0;
}

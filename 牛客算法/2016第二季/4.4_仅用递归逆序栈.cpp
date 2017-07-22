/*
 * 题目：如何仅用递归函数和栈操作逆序一个栈，不能用其他数据结构。
 */
#include <iostream>
#include <stack>

using namespace std;

// 把一个栈的栈底元素弹出，其他元素不变
// 不用额外空间怎么处理？依靠递归本身的栈结构！
// 注意形参必须是引用
int getAndRemoveLast(stack<int> &stack)
{
	int res = stack.top();
	stack.pop();
	if (stack.empty())
		return res;
	else {
		int last = getAndRemoveLast(stack);
		stack.push(res);
		return last;
	}
}

// 注意形参必须是引用
void reverseStack(stack<int> &stack)
{
	if (stack.empty())
		return;
	int i = getAndRemoveLast(stack);
	reverseStack(stack);
	stack.push(i);
}

// 输出栈的数据
void StackPrint(stack<int> stack)
{
	while (!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
}

int main()
{
	stack<int> stack;
	stack.push(3); stack.push(6); stack.push(13);
	StackPrint(stack);
	reverseStack(stack);
	StackPrint(stack);

	return 0;
}

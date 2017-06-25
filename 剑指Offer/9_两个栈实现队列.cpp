/*
 * 使用两个栈实现队列
 */
#include <iostream>
#include <stack>

using namespace std;

stack<int> stack1; // 队列的进队位置，队尾
stack<int> stack2; // 队列的出队位置，队首

// 输出队列的数据
// stack2是队首所以先stack2后stack1
void QueuePrint()
{
	while (!stack2.empty()) {
		cout << stack2.top() << " ";
		stack2.pop();
	}
	while (!stack1.empty()) {
		cout << stack1.top() << " ";
		stack1.pop();
	}
	cout << endl;
}

void QueuePush(int val)
{
	stack1.push(val);
}

void QueuePop()
{
	// 如果stack2为空，则把stack1所有数据转到stack2
	if (stack2.empty()) {
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	// 否则直接把stack2的首数据出栈
	stack2.pop();
}


int main()
{
	QueuePush(1);
	QueuePush(13);
	QueuePush(6);
	QueuePush(7);
	QueuePush(23);
	QueuePop(); // 1出队
	QueuePop(); // 13出队
	QueuePrint(); // 输出 6 7 23

	return 0;
}

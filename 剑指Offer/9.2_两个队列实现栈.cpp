/*
 * 使用两个队列实现栈，思路：要弹出的时候把进队的那个队列只留一个即要弹出的那个
 * 然后其他的元素都进入辅助队列，弹出数据队列剩的那个之后，把辅助队列元素又还回去数据队列
 */
#include <iostream>
#include <queue>

using namespace std;

queue<int> queue1; // 队列的进队位置，队尾
queue<int> queue2; // 队列的出队位置，队首

// 输出栈的数据
void StackPrint()
{
	while (!queue1.empty()) {
		cout << queue1.front() << " ";
		queue1.pop();
	}
	cout << endl;
}

void StackPush(int val)
{
	queue1.push(val);
}

void StackPop()
{
	// 转移除了最后进入的其余数据
	while (!queue1.empty() && queue1.size() != 1) {
		queue2.push(queue1.front());
		queue1.pop();
	}
	// 弹出最后进队的数据
	queue1.pop();
	// 把转移的数据重新移回到原队列
	while (!queue2.empty()) {
		queue1.push(queue2.front());
		queue2.pop();
	}
}


int main()
{
	StackPush(3); StackPush(6); StackPush(9); // 栈压入3,6,9
	StackPop(); // 弹出9
	StackPush(13); StackPush(2); // 压入13,2
	StackPop(); // 弹出2
	StackPrint(); // 输出3,6,13

	return 0;
}

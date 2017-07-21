/*
 * 题目：定义一个栈的数据结构，在该类型中实现min函数返回当前栈的最小值
 */
#include <iostream>
#include <stack>

using namespace std;

// 方法一：逻辑简单，费空间
class minStack1 {
private:
	stack<int> dataStack;
	stack<int> minStack;
public:
	void push(int val) {
		dataStack.push(val);
		if (minStack.empty() || val < minStack.top())
			minStack.push(val);
		// 如果小于最小值，重新把最小值压入辅助栈
		else
			minStack.push(minStack.top());
	}
	void pop() {
		dataStack.pop();
		minStack.pop();
	}
	int min() {
		return minStack.top();
	}
};

// 方法二：逻辑稍微复杂，节省空间
class minStack2 {
private:
	stack<int> dataStack;
	stack<int> minStack;
public:
	void push(int val) {
		dataStack.push(val);
		// 小于等于时辅助栈要压入，不要忽略等于的情况
		// 大于时辅助栈不用操作，节省空间
		if (minStack.empty() || val <= minStack.top())
			minStack.push(val);
	}
	void pop() {
		int top = dataStack.top();
		dataStack.pop();
		// 如果数据栈弹出数据为辅助栈顶，则同步弹出
		// 数据栈元素只会大于等于辅助栈，大于时不用处理
		if(top == minStack.top())
			minStack.pop();
	}
	int min() {
		return minStack.top();
	}
};

int main()
{
	minStack1 mS1;
	mS1.push(5); mS1.push(3); cout << mS1.min() << endl;
	mS1.push(6); mS1.push(2); cout << mS1.min() << endl;
	mS1.pop(); cout << mS1.min() << endl;

	minStack1 mS2;
	mS2.push(5); mS2.push(3); cout << mS2.min() << endl;
	mS2.push(6); mS2.push(2); cout << mS2.min() << endl;
	mS2.pop(); cout << mS2.min() << endl;

	return 0;
}

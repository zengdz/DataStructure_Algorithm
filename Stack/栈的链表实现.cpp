/*
 * 使用链表简单实现栈,本质上是链表在head插入和删除
 */
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* link;
};

Node* top = nullptr; // 栈顶就是链表的头指针

void ListStackPush(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->link = top;
	top = temp;
}

void ListStackPop()
{
	if (top == nullptr) {
		cout << "Error: no element to pop!" << endl;
		return;
	}
	Node* temp = top; 
	top = top->link;// top就是头节点的地址，top->link是第二个节点的地址
	delete temp; // 释放temp指向的堆上内存，temp是局部变量最后也会释放
}

void Print(Node* n)
{
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->link;
	}
	cout << endl;
}

int main()
{
	ListStackPush(1);
	ListStackPush(13);
	ListStackPush(6);
	Print(top);
	ListStackPop();
	Print(top);
	ListStackPush(9);
	Print(top);

	return 0;
}

/*
 * 链表顺序输出或者翻转输出
 * 可以是不改变链表而翻转输出，也可以是修改链表进行翻转
 * 可以是使用迭代，也可以是使用递归实现
 */
#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int data;
	Node *next; // 对于C++可以省略前面的struct关键字
};

void AddToHead(Node **pHead, int value)
{
	Node *pNew = new Node();
	pNew->data = value;
	pNew->next = nullptr;
	pNew->next = *pHead;
	*pHead = pNew;
}

// 迭代顺序输出链表
void printList(Node *n)
{
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

// 不修改链表，迭代逆序输出
// 递归的本质还是栈，所以可以用栈实现
void printListReverse(Node *n)
{
	stack<Node*> s;
	while (n != nullptr) {
		s.push(n);
		n = n->next;
	}
	while (!s.empty()) {
		Node* temp = s.top();
		cout << temp->data << " ";
		s.pop();
	}
	cout << endl;
}

// 递归顺序输出链表
void printListRecursive(Node *n)
{
	if (n == nullptr) {
		cout << endl; 
		return;
	}
	cout << n->data << " ";
	printListRecursive(n->next);
}

// 递归逆序输出链表
// 可在调用函数后加一个换行语句
void printListReverseRecursive(Node *n)
{
	if (n == nullptr) {
		return;
	}
	printListReverseRecursive(n->next);
	cout << n->data << " ";
}

// 改变原链表结构，迭代实现链表翻转
// 画出逻辑图更好理解代码流程
void LinkListReverse(Node **pHead)
{
	if (pHead == nullptr) 
		return;
	Node *current, *prev, *next;
	current = *pHead;
	prev = nullptr;
	while (current != nullptr) {
		next = current->next; // 保存下一个节点指针
		current->next = prev; // 指向前一个指针
		prev = current; // 更新指向
		current = next; // 更新指向
	}
	*pHead = prev; // 头指针的位置更新
}

// 改变链表结构，递归实现链表翻转
// 递归实现必须返回新的头结点，不能直接修改头结点
// 所以形参是头指针而非指针的指针
Node* LinkListReverseRecursive(Node *pHead)
{
	if (pHead == nullptr || pHead->next == nullptr) {
		return pHead;
	}
	else {
		Node *newHead = LinkListReverseRecursive(pHead->next);
		// 从后往前更新节点next的指向
		pHead->next->next = pHead;
		pHead->next = nullptr;
		return newHead;
	}
}

int main()
{
	Node *head = nullptr;
	AddToHead(&head, 1);
	AddToHead(&head, 13);
	AddToHead(&head, 6);

	printList(head);
	printListRecursive(head);
	printListReverse(head);
	Node * newHead = LinkListReverseRecursive(head);
	printList(newHead);

	return 0;
}

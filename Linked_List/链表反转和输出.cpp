
#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
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
// 如果是要把链表元素逆序保存到向量
void printListReverseRecursive(Node *n)
{
	if (n == nullptr) {
		return;
	}
	printListReverseRecursive(n->next);
	cout << n->data << " ";
}

// 改变原链表结构，修改指针的指向
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

int main()
{
	Node *head = nullptr;
	AddToHead(&head, 1);
	AddToHead(&head, 13);
	AddToHead(&head, 6);
	printList(head);
	LinkListReverse(&head);
	printListRecursive(head);
	printListReverseRecursive(head);
	return 0;
}

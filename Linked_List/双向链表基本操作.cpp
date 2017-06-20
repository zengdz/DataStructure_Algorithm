/*
 * 双向链表基本操作
 */
#include <iostream>

using namespace std;

// 双向链表的数据结构
// 一个数据和两个节点指针，分别指向前后节点
struct Node {
	int data;
	Node *prev;
	Node *next;
};

void InsertAtHead(Node **pHead, int x)
{
	Node *newNode = new Node();
	newNode->data = x;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	// 如果是空链表，直接把头指针指向新节点即可
	if (*pHead == nullptr) {
		*pHead = newNode;
		return;
	}
	(*pHead)->prev = newNode; // 原头结点的prev需要更新
	newNode->next = *pHead; // 新的头结点的next指向旧头节点
	*pHead = newNode; // 更新头指针的指向
}

// 正序输出打印
void Print(Node *head)
{
	Node *temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// 逆序输出打印
void ReversePrint(Node *head)
{
	Node *temp = head;
	if (temp == nullptr)
		return;
	// 先正序指到链表的末尾
	while(temp->next != nullptr){
		temp = temp->next;
	}
	// 再从末尾往前依次输出
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int main()
{
	Node *head = nullptr;
	InsertAtHead(&head, 1);
	InsertAtHead(&head, 13);
	InsertAtHead(&head, 6);

	Print(head); // 6 13 1
	ReversePrint(head); // 1 13 6

	return 0;
}

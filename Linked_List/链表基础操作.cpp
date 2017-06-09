#include <stdio.h>
#include <iostream>

using namespace std;

// 链表数据结构是一个结构体
// 包含一个数据和指向下一节点的指针
struct Node {
	int data;
	struct Node *next;
};

// 在链表末尾添加一个节点
// 注意形参是一个指向指针的指针，可以修改指针
void AddToTail(Node **pHead, int value)
{
	// 动态分配内存，每次分配一个
	Node *pNew = new Node;
	pNew->data = value;
	pNew->next = nullptr;

	// 如果链表为空，则把新节点作为头结点
	if (*pHead == nullptr)
		*pHead = pNew;
	else {
		Node *pNode = *pHead; // 定义一个指针节点用于遍历链表
		while (pNode->next != nullptr)
			pNode = pNode->next;
		// 找到next成员为nullptr的节点即末尾，将其指向新的节点
		pNode->next = pNew;
	}
}

// 删除链表中第一个值为value的节点
void RemoveNode(Node **pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;
	Node *pToBeDeleted = nullptr;
	if ((*pHead)->data == value) {
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else {
		Node *pNode = *pHead;
		while (pNode->next != nullptr && pNode->next->data != value)
			pNode = pNode->next;
		if (pNode->next != nullptr && pNode->next->data == value) {
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}
	if (pToBeDeleted != nullptr) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

// 打印输出链表
void printList(struct Node *n)
{
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

int main(){

	Node *head = new Node;
	head->data = 1;
	head->next = nullptr;

	AddToTail(&head, 5);
	AddToTail(&head, 13);
	AddToTail(&head, 1);
	printList(head);

	RemoveNode(&head, 1);
	printList(head);

	return 0;
}

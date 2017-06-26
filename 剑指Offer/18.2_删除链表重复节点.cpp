/*
 * 删除链表中重复的节点
 * 注意是删除重复的所有节点，而非剩一个
 * 比如链表 1->2->3->3->4->4->5 处理后为 1->2->5
 */
#include <iostream>

using namespace std;

// 包含构造函数的节点类
// 不再是简单的结构体
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

void AddToHead(ListNode **pHead, int value)
{
	ListNode *pNew = new ListNode(value);
	pNew->next = *pHead;
	*pHead = pNew;
}

// 迭代顺序输出链表
void printList(ListNode *n)
{
	while (n != nullptr) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	// 如果链表为空或者只有一个节点，不存在重复的情况
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;
	// 创建辅助节点，画出链表节点图帮助理解
	ListNode* temp = new ListNode(-1);
	temp->next = pHead;
	ListNode* prev = temp;
	ListNode* pNode = pHead;
	bool flag = false;
	while (pNode && pNode->next) {
		// 如果当前节点和下一节点的数值相同
		// 则当前节点指向下下节点，并指示flag存在重复
		while (pNode->next && pNode->val == pNode->next->val) {
			pNode->next = pNode->next->next;
			flag = true;
		}
		// 如果数据存在重复
		// 把prev指向剩余的重复节点(2 2 3 -> 2 3)，prev指向2
		// pNode向后移动
		if (flag) {
			flag = false;
			prev->next = pNode->next;
			pNode = pNode->next;
		}
		// 如果没有重复数据
		// 两个节点指针直接向后移动一位
		else {
			pNode = pNode->next;
			prev = prev->next;
		}
	}
	// prev和temp指向相同，prev指向的是剩余的重复节点
	// 所以下一个节点才是不重复的节点
	return temp->next;
}

int main()
{
	ListNode* head = nullptr;
	AddToHead(&head, 1); AddToHead(&head, 2);
	AddToHead(&head, 3); AddToHead(&head, 3);
	AddToHead(&head, 4); AddToHead(&head, 4);
	AddToHead(&head, 13);
	printList(head); // 13 4 4 3 3 2 1

	ListNode* newHead = deleteDuplication(head);
	printList(newHead); // 13 2 1

	return 0;
}

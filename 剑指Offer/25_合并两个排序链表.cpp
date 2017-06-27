/*
 * 合并两个排序链表，和合并两个排序数组原理类似
 * 分别使用迭代法、递归法实现，注意两种实现的区别
 */
#include <iostream>

using namespace std;

// 包含构造函数的节点类
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

void AddToHead(ListNode **pHead, int value)
{
	ListNode *pNew = new ListNode(value);
	pNew->next = *pHead;
	*pHead = pNew;
}

void printList(ListNode *n)
{
	while (n != nullptr) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

// 迭代法合并，和合并两个排序数组原理类似
// 但操作对象是链表，需要注意头指针处理
ListNode* MergeIterative(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr && pHead2 == nullptr)
		return nullptr;
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	// 最后要返回头指针，必须指向一个固定位置
	// pHead是个局部指针，但是指向的是分配在堆上的节点
	ListNode* pHead = new ListNode(0);
	ListNode* pNode = pHead;
	while (pHead1 && pHead2) {
		if (pHead1->val < pHead2->val) {
			pNode->next = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			pNode->next = pHead2;
			pHead2 = pHead2->next;
		}
		pNode = pNode->next;
	}
	// 剩下的不用比较，直接把剩余部分连起来即可
	if (pHead1)
		pNode->next = pHead1;
	if (pHead2)
		pNode->next = pHead2;
	return pHead->next;
}

// 递归法合并两个排序链表
ListNode* MergeRecursive(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1 && !pHead2)
		return nullptr;
	// 不仅是初始的空指针判断
	// 当某一头指针为空时，返回另一个链表的剩余部分
	if (!pHead1) return pHead2;
	if (!pHead2) return pHead1;
	ListNode* pMergeHead = nullptr;
	// 使用递归不会破坏头指针，不用在堆上分配
	if (pHead1->val < pHead2->val) {
		pMergeHead = pHead1;
		pMergeHead->next = MergeRecursive(pHead1->next, pHead2);
	}
	else {
		pMergeHead = pHead2;
		pMergeHead->next = MergeRecursive(pHead1, pHead2->next);
	}
	return pMergeHead;
}

int main()
{
	ListNode* head1 = nullptr;
	AddToHead(&head1, 13);
	AddToHead(&head1, 9);
	AddToHead(&head1, 3);
	ListNode* head2 = nullptr;
	AddToHead(&head2, 10);
	AddToHead(&head2, 7);
	AddToHead(&head2, 1);

	// 两种解法一次只能运行一种，不能合并两次
	ListNode* MergeHeadIter = MergeIterative(head1, head2);
	printList(MergeHeadIter);

	return 0;
}

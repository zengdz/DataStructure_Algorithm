/*
 * 如果链表包含环，找出环的入口节点
 * 根据是否存在环，是否允许破坏链表，有不同的解法
 */
#include <iostream>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

// 破坏链表且假定一定存在环
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	// 处理链表为空和只有一个节点情况
	if (pHead == nullptr || pHead->next == nullptr)
		return nullptr;
	ListNode* pBehind = pHead;
	ListNode* pAhead = pBehind->next;
	// 每走一步就断开后路，最后只剩一个节点
	// 如果存在环，剩的那个节点就是入口
	while (pAhead) {
		pBehind->next = nullptr;
		pBehind = pAhead;
		pAhead = pAhead->next;
	}
	return pBehind;
}

// 判断是否存在环，如果存在找出入口，不破坏链表
ListNode* EntryNodeIfLoop(ListNode* pHead)
{
	// 处理链表为空和只有一个节点情况
	if (pHead == nullptr || pHead->next == nullptr)
		return nullptr;
	ListNode* pSlow = pHead;
	ListNode* pFast = pHead;
	while (pFast != nullptr && pFast->next != nullptr) {
		// 慢指针每次走一步，快指针每次走两步
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		// 如果两指针相等，此时慢指针走了一个环的步数！
		// 但该位置不一定是入口位置
		if (pSlow == pFast) {
			pFast = pHead; // 让pFast从头开始
			// 两个指针单步长遍历，再次相等的时候就是入口
			while (pSlow != pFast) {
				pSlow = pSlow->next;
				pFast = pFast->next;
			}
			return pSlow;
		}
	}
	return nullptr;
}

// 如果可以知道哪个节点重复，就知道哪里是入口
// 使用map容器
ListNode* EntryNodeIfLoopUseMap(ListNode* pHead)
{
	// 处理链表为空和只有一个节点情况
	if (pHead == nullptr || pHead->next == nullptr)
		return nullptr;
	ListNode* pNode = pHead;
	map<ListNode*, int> temp;
	// 如果节点出现次数为2次，该节点即入口
	while ((temp[pNode]++) < 2){
		pNode = pNode->next;
	}
	return pNode;
}

int main()
{

	return 0;
}

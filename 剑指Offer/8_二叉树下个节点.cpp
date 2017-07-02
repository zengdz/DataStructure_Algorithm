/*
 * 题目：给定一颗二叉树和其中一个节点，找出中序遍历的下一节点
 * 分析二叉树的下一个节点，一共有以下情况：
 * 1.二叉树为空，则返回空；
 * 2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
 * 3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
 */
#include <iostream>

using namespace std;

// 包含指向左右节点的指针，以及指向父节点的指针(next)
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;
	if (pNode->right != nullptr) {
		TreeLinkNode* pRight = pNode->right;
		while (pRight->left != nullptr)
			pRight = pRight->left;
		return pRight;
	}
	while (pNode->next != nullptr) {
		TreeLinkNode* pRoot = pNode->next;
		if (pRoot->left == pNode)
			return pRoot;
		pNode = pNode->next;
	}
	return nullptr;
}

/*
 * 题目：输入一颗二叉树的根节点，判断该树是不是二叉树
 * 如果树中任意节点的左，右子树的深度相差不超过1，则为平衡二叉树
 */
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) { }
};

// 法一：简单直观，需要计算每个节点左右子树的深度
// 需要重复遍历节点多次，时间效率不高
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int leftHeight = TreeDepth(pRoot->left);
	int rightHeight = TreeDepth(pRoot->right);
	return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == nullptr)
		return true;
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	int diff = left - right;
	if (diff > 1 || diff < -1)
		return false;
	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

// 法二：后序遍历二叉树，遍历节点之前就遍历了左右子树
// 遍历节点的时候记录深度，就可以一边遍历一边判断每个节点是否平衡
bool IsBalanced(TreeNode *root, int & depth) {
	if (root == nullptr)
		return true;
	int left = 0;
	int right = 0;
	if (IsBalanced(root->left, left) && IsBalanced(root->right, right)) {
		int dif = left - right;
		if (dif<-1 || dif >1)
			return false;
		depth = (left > right ? left : right) + 1;
		return true;
	}
	return false;
}
bool IsBalanced(TreeNode* pRoot) {
	int depth = 0;
	return IsBalanced(pRoot, depth);
}

int main()
{

	return 0;
}

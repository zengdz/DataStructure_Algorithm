/*
* 题目：给定一颗二叉搜索树，找出其中第K个节点（从小到大排序）
* 对二叉树进行中序遍历就是从小到大遍历，因为根节点在中间，左边小，右边大
*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* KthNodeCore(TreeNode* pRoot, int &k) {
	TreeNode* target = nullptr;
	// 一直递归找到最左边的节点，即最小的节点
	if (pRoot->left != nullptr)
		target = KthNodeCore(pRoot->left, k);
	if (target == nullptr) {
		// 当K值减到1时，指向的就是第K节点
		if (k == 1)
			target = pRoot;
		--k;
	}
	if (target == nullptr && pRoot->right != nullptr)
		target = KthNodeCore(pRoot->right, k);
	return target;
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k < 1)
		return nullptr;
	return KthNodeCore(pRoot, k);
}

int main()
{

	return 0;
}

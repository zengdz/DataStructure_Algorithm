/*
 * 题目：判断一颗二叉树是否对称
 * 如果一颗二叉树和它的镜像一样，那么它是对称的
 */
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) 
{
	if (!pRoot1 && !pRoot2) 
		return true;
	if (!pRoot1 || !pRoot2) 
		return false;
	if (pRoot1->val != pRoot2->val) 
		return false;
	return isSymmetrical(pRoot1->left, pRoot2->right) 
		&& isSymmetrical(pRoot1->right, pRoot2->left);
}

bool isSymmetrical(TreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

int main()
{
	return 0;
}

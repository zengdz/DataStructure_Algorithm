/*
* 题目：输入两颗二叉树A和B，判断B是不是A的子结构
*/
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 判断A中以R为根节点的子树是否包含和树B一样的结构
bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;
	return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && 
		DoesTree1HasTree2(pRoot1->right, pRoot2->right);
}

// 先遍历寻找和树B根节点值一样的节点R
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 && pRoot2) {
		if (pRoot1->val == pRoot2->val)
			result = DoesTree1HasTree2(pRoot1, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->left, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}

int main()
{
	return 0;
}

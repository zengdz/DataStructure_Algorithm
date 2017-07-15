/*
* 题目：输入一颗二叉树，输出它的镜像
*/
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法
void MirrorRecursive(TreeNode *pRoot) 
{
	if(pRoot == nullptr) 
		return;
    if(pRoot->left == nullptr && pRoot->right == nullptr) 
		return;
    swap(pRoot->left, pRoot->right);
    if(pRoot->left)
		MirrorRecursive(pRoot->left);
    if(pRoot->right)
		MirrorRecursive(pRoot->right);
}

// 迭代法
void Mirror(TreeNode *pRoot)
{
	if (pRoot == nullptr)
		return;
	queue<TreeNode*> qu;
	TreeNode* p = nullptr;
	qu.push(pRoot);
	while (!qu.empty()) {
		p = qu.front();
		qu.pop();
		swap(p->left, p->right);
		if (p->left)
			qu.push(p->left);
		if (p->right)
			qu.push(p->right);
	}
}

int main()
{
	return 0;
}

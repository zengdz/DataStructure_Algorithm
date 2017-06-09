/* 
 * 二叉树的深度和高度（Depth & Height of Binary Tree）
 * 深度是以根节点为基准往下的长度；高度以叶节点为基准往上的长度
 * 注意是否把根节点算入深度，或者把叶节点算入高度
 */

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

// 查找一个节点的高度
// 也可以用于计算树的深度，传入根节点作参数
int FindHeight(Node *root)
{
	if (root == nullptr)
		// 如果把叶节点算入高度则返回0，否则返回-1
		// 如果把根节点算入深度则返回0，否则返回-1
		return -1;
	int leftHeight = FindHeight(root->left);
	int rightHeight = FindHeight(root->right);
	// 返回左右子树的较大高度，再加上根节点得到最后高度
	return leftHeight >= rightHeight ? leftHeight + 1: rightHeight + 1;
}

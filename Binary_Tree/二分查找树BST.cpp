/*
 * 二分查找树(BinarySearchTree)
 * 左子树要小于等于根节点，右子树要大于等于根节点
 * 平衡二叉树，根节点的左右高度的绝对值差不超过一
 */
#include <iostream>

using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* GetNewNode(int data)
{
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

// 采用递归方式容易理解，也可使用迭代
// 形参root在递归时代表的是每个子树的根节点
BSTNode* Insert(BSTNode* root, int data)
{
	if (root == nullptr)
		root = GetNewNode(data);
	else if (data <= root->data) 
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

// 在二叉搜索树中找指定数据，递归方式
bool Search(BSTNode* root, int data)
{
	if (root == nullptr)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}

int main()
{
	// 和链表一样，有一个指向根节点的指针
	BSTNode* root = nullptr;
	root = Insert(root, 3);
	root = Insert(root, 6);
	root = Insert(root, 13);
	root = Insert(root, 9);

	cout << Search(root, 9) << endl; // 搜索成功，输出1
	cout << Search(root, 11) << endl; // 搜索失败，输出0

	return 0;
}

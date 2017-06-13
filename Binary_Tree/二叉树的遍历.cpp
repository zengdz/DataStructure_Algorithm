/*
 * 二叉树遍历6+1（6种深度优先+1种广度优先）
 * 其中深度优先分别是前序遍历、中序遍历、后序遍历的递归和迭代版
 * 广度优先遍历只有迭代版无递归版
 */
#include <stdio.h>
#include <iostream>
#include <queue> // 用于广度优先遍历
#include <stack> // 用于深度优先遍历的迭代版

using namespace std;

// 二叉树的数据结构表示
// 包含一个数据以及指向左右子树的节点指针
struct Node
{
	int data;
	Node *left;
	Node *right;
};

// 递归版
// 深度优先遍历：Depth-first 前序遍历；中序遍历；后序遍历
void Preorder(Node *root)
{
	if (root == nullptr)
		return;
	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node *root)
{
	if (root == nullptr)
		return;
	Preorder(root->left);
	printf("%d ", root->data);
	Preorder(root->right);
}

void Postorder(Node *root)
{
	if (root == nullptr)
		return;
	Preorder(root->left);
	Preorder(root->right);
	printf("%d ", root->data);
}

// 前序遍历--非递归迭代版
void PreOrder(Node *root) 
{
	if (root == nullptr)
		return;
	stack <Node *> S;
	Node* p = root;
	while (p != nullptr || !S.empty()) {
		// 一路向左寻找左节点
		while (p != nullptr) {
			cout << p->data << " "; // 在一开始输出节点
			S.push(p);
			p = p->left;
		}
		// 如果左边到底，则边退栈边找右节点
		if (!S.empty()) {
			p = S.top();
			S.pop();
			p = p->right;
		}
	}
}

// 中序遍历--非递归迭代版
void InOrder(Node *root)
{
	if (root == nullptr)
		return;
	stack <Node *> S;
	Node* p = root;
	while (p != nullptr || !S.empty()) {
		// 一路向左寻找左节点
		while (p != nullptr) {
			S.push(p);
			p = p->left;
		}
		// 如果左边到底，则边退栈边找右节点
		if (!S.empty()) {
			p = S.top();
			cout << p->data << " "; // 在中间输出节点
			S.pop();
			p = p->right;
		}
	}
}

// 后序遍历--非递归迭代版
// 和前面两种不一样，最复杂
void PostOrder(Node *root)
{
	if (root == nullptr)
		return;
	stack <Node *> S;
	Node* cur; // 当前节点
	Node* pre = nullptr; // 前一次访问的节点
	S.push(root);
	while (!S.empty()) {
		cur = S.top();
		if((cur->left == nullptr && cur->right == nullptr) ||
		(pre != nullptr && (pre == cur->left || pre == cur->right))){
			cout << cur->data << " ";
			S.pop();
			pre = cur;
		}
		else {
			if (cur->right != nullptr)
				S.push(cur->right);
			if(cur->left != nullptr)
				S.push(cur->left);
		}
	}
}

// 广度优先遍历 Breadth-first 只能迭代无递归版
// 时间复杂度：O(n) 空间复杂度：最好O(1) 最坏/平均O(n)
void LevelOrder(Node *root)
{
	if (root == nullptr)
		return;
	queue <Node*> Q; // 使用队列保存节点指针
	Q.push(root);
	while (!Q.empty()) {
		Node *current = Q.front();
		cout << current->data << " ";
		if (current->left != nullptr)
			Q.push(current->left);
		if (current->right != nullptr)
			Q.push(current->right);
		Q.pop();
	}
}

int main()
{

	return 0;
}


#include <iostream>
#include <stack> 

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

// 前序遍历：根左右
// 思路：每个节点都可看作左右子树的根节点
// 从根节点出发压栈，输出栈顶，找右节点压栈，找左节点压栈
void preOrder(Node* root) {
	if (root == nullptr)
		return;
	stack<Node*> stack;
	stack.push(root);
	while (!stack.empty()) {
		Node* head = stack.top();
		stack.pop();
		cout << head->data;
		if (head->right)
			stack.push(head->right);
		if (head->left)
			stack.push(head->left);
	}
}

// 中序遍历：左根右
// 思路：一直往左遍历，若到底弹出打印并跳到右边(如果有)
// 然后又继续往左遍历
void inOrder(Node* root) {
	if (root == nullptr)
		return;
	stack<Node*> stack;
	Node* head = root;
	while (!stack.empty() || head != nullptr) {
		if (head->left) {
			stack.push(head->left);
			head = head->left;
		}
		else {
			head = stack.top();
			stack.pop();
			cout << head->data;
			head = head->right;
		}
	}
}

// 后序遍历：左右根
// 根据前两个：根左右->根右左->左右根
// 思路：把前序遍历的左右顺序调换，然后再放到栈中逆序
void postOrder(Node* root) {
	if (root == nullptr)
		return;
	stack<Node*> stack1;
	stack<Node*> stack2;
	stack1.push(root);
	while (!stack1.empty()) {
		Node* head = stack1.top();
		stack1.pop();
		stack2.push(head);		
		if (head->left)
			stack1.push(head->left);
		if (head->right)
			stack1.push(head->right);
	}
	while (!stack2.empty()) {
		cout << stack2.top();
		stack.pop();
	}
}

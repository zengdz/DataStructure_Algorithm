/*
 * 题目：输入一颗二叉树和一个整数，打印二叉树中节点值和为该整数的所有路径
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) { }
};

void findTreePath(TreeNode* root, int num, vector<int> &path, vector<vector<int>> &res)
{
	if (num < 0) return;
	path.push_back(root->val);
	// 如果是叶节点，节点值又和剩余值相同则为一个路径
	if (root->left == nullptr && root->right == nullptr) {
		if (num - root->val == 0)
			res.push_back(path);
	}
	if (root->left)
		findTreePath(root->left, num - root->val, path, res);
	if (root->right)
		findTreePath(root->right, num - root->val, path, res);
	path.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
{
	vector<vector<int>> res;
	vector<int> path;
	if (root)
		findTreePath(root, expectNumber, path, res);
	return res;
}

// 迭代法
vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int>> res;
	if (root == nullptr) return res;
	vector<int> CurPath;
	stack<TreeNode*> s;
	s.push(root);
	TreeNode *Cur = root, *last = NULL;
	int sum = 0;
	while (!s.empty()) {
		if (Cur == NULL) {
			TreeNode *tmp = s.top();
			if (tmp->right != NULL && tmp->right != last) {
				Cur = tmp->right;
			}
			else {
				last = tmp;
				s.pop();
				CurPath.pop_back();
				sum -= tmp->val;
			}
		}
		else {
			s.push(Cur);
			sum += Cur->val;
			CurPath.push_back(Cur->val);
			if (Cur->left == NULL&&Cur->right == NULL&&sum == expectNumber)
				res.push_back(CurPath);
			Cur = Cur->left;
		}
	}
	return res;
}

int main()
{

	return 0;
}

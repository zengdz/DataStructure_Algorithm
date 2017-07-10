/*
 * 题目：从上到下打印二叉树
 * 有很多变体，换行打印，之字形打印
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从上到下依次输出到向量中，不分行
vector<int> PrintUpToDown(TreeNode *root)
{
	vector<int> res;
	if (root == nullptr) 
		return res;
	queue<TreeNode*> Q;
	Q.push(root);
	while (!Q.empty()) {
		TreeNode* cur = Q.front();
		Q.pop();
		res.push_back(cur->val);
		if (cur->left)
			Q.push(cur->left);
		if(cur->right)
			Q.push(cur->right);
	}
	return res;
}

// 从上到下依次输出到向量中，要分行
// 需要判断每一行什么时候结束
vector<vector<int>> PrintUpToDownEachLine(TreeNode *pRoot)
{
	vector<vector<int>> res;
	if (pRoot == nullptr)
		return res;
	queue<TreeNode*> Q;
	Q.push(pRoot);
	while (!Q.empty()) {
		int levelLength = Q.size(); // 根据每一层元素的数量来判断分行位置
		vector<int> levelElem; // 保存每一层元素的向量
		// 循环内部和不分行版本是一样的
		while (levelLength--) {
			TreeNode* cur = Q.front();
			Q.pop();
			levelElem.push_back(cur->val);
			if (cur->left)
				Q.push(cur->left);
			if (cur->right)
				Q.push(cur->right);
		}
		// 把不同行的结果汇总到向量
		res.push_back(levelElem);
	}
	return res;
}

// 从上到下依次按之字形输出到向量中，要分行
vector<vector<int>> PrintUpToDownZigzag(TreeNode *pRoot)
{
	vector<vector<int>> res;
	if (pRoot == nullptr)
		return res;
	stack<TreeNode*> levels[2];
	int cur = 0;
	int next = 1;
	levels[cur].push(pRoot);
	vector<int> row;
	while (!levels[0].empty() || !levels[1].empty()) {
		TreeNode * node = levels[cur].top();
		row.push_back(node->val);
		levels[cur].pop();
		if (cur == 0) {
			if (node->left)
				levels[next].push(node->left);
			if (node->right)
				levels[next].push(node->right);
		}
		else {
			if (node->right)
				levels[next].push(node->right);
			if (node->left)
				levels[next].push(node->left);
		}
		if (levels[cur].empty()) {
			res.push_back(row);
			row.clear();
			cur = 1 - cur;
			next = 1 - next;
		}
	}
	return res;
}

int main()
{

	return 0;
}

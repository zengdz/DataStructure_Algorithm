#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从上到下依次分行输出到向量中
// 需要判断每一行什么时候结束
vector<vector<int>> PrintUpToDownEachLine(TreeNode *pRoot) {
	vector<vector<int>> res;
	if (pRoot == nullptr)
		return res;
	queue<TreeNode*> Q;
	Q.push(pRoot);
	TreeNode *last = pRoot; // 正在打印的当前行的最右节点
	TreeNode *nlast = nullptr; // 下一行的最右节点
	vector<int> levelElem; // 保存每一层元素的向量
	while (!Q.empty()) {
		TreeNode* cur = Q.front();
		Q.pop();
		levelElem.push_back(cur->val); // 弹出则输出或者保存
		if (cur->left) {
			Q.push(cur->left);
			nlast = cur->left;
		}
		if (cur->right) {
			Q.push(cur->right);
			nlast = cur->right;
		}
		// 放在最后判断，因为前面要更新nlast
		if (cur == last) {
			res.push_back(levelElem);
			last = nlast;
			levelElem.clear();
		}
	}
	return res;
}

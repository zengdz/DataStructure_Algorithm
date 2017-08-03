#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// level代表上一层的高度(深度)，认为根节点为1
int getHeight(TreeNode* pRoot, int level) {
	if (pRoot == nullptr)
		return level;
	int lh = getHeight(pRoot->left, level + 1);
	int rl = getHeight(pRoot->right, level + 1);
	if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
		return -1;
	return max(lh, rh);
}
// 平衡二叉树：左右子树的深度绝对值不超过1
bool isBalance(TreeNode *pRoot) {
	return getHeight(pRoot, 0) != -1;
}

// 完全二叉树：每一层节点要么全满，如果不满则节点从左边开始连续至不满
// 情况1：若左节点为空，右节点不为空，显然不是完全二叉树
// 情况2：如果发现了叶节点，在这之后如果有非节点，也不是完全二叉树
// 叶节点阶段：左节点存在右节点不存在，或者都不存在，这两种情况进入叶节点阶段
// 合并一下就是：如果右节点不存在就进入叶节点阶段
bool isFullTree(TreeNode* pRoot) {
	if (pRoot == nullptr)
		return false;
	queue<TreeNode*> queue;
	queue.push(pRoot);
	bool leaf = false; // 若找到1个叶节点则进入叶节点阶段
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	while (!queue.empty()) {
		TreeNode* cur = queue.front();
		queue.pop();
		left = cur->left;
		right = cur->right;
		if ((leaf && (!left || !right)) || (!left && right))
			return false;
		if (left)
			queue.push(left);
		if (right)
			queue.push(right);
		else
			leaf = true;
	}
}

// 搜索二叉树：左子树比根节点小，右子树比根节点大
// 思路：按照中序遍历判断是否是递增
bool isBST() {

}

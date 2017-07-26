/*
 * 给定一个数组，其中当然有很多的子数组，在所有两个子数组的组合中
 * 找到相加和最大的一组，要求两个子数组无重合的部分。最后返回累加和
 */
#include <vector>
#include <algorithm>

using namespace std;

// 算法原型：在数组中找子数组最大和
int SubArrayMaxSum(vector<int> array) {
	if (array.empty())
		return 0;
	int res = array[0];
	int cur = array[0];
	// 第一个元素已经统计，遍历时下标从1而不是从0开始
	for (int i = 1; i < array.size(); ++i) {
		// 如果当前和小于0则清零，否则不变
		cur = cur < 0 ? 0 : cur;
		cur += array[i]; // 累加遍历元素值
		res = max(cur, res); // 更新最大值
	}
	return res;
}

// 找出数组中不重合的两个子数组最大累加和
int TwoSubArrayMaxSum(vector<int> array) {
	if (array.empty() || array.size() < 2)
		return 0;
	int length = array.size();
	int maxSum = array[length - 1]; // 从右遍历
	int curSum = array[length - 1];
	vector<int> rhs(length); // rhs[i]表示索引大于等于i的右半边子数组最大和
	rhs[length - 1] = array[length - 1];
	// 辅助数组末尾元素要手动赋值，注意循环下标
	for (int i = length - 2; i >= 0; i--) {
		curSum = curSum < 0 ? 0 : curSum;
		curSum += array[i];
		rhs[i] = max(curSum, maxSum);
	}
	int maxSum = array[0]; // 使用相同变量从左遍历
	int curSum = array[0];
	// res是两边子数组的最大和相加，初始值需赋值
	int res = array[0] + rhs[1];
	// 不必计算lhs辅助数组，在从左至右划分时可以同时计算
	// 注意起止下标，结束在倒数第二位置(右边至少有1个元素)
	for (int i = 1; i < length - 1; ++i) {
		curSum = curSum < 0 ? 0 : curSum;
		curSum += array[i];
		maxSum = max(curSum, maxSum);
		res = max(res, maxSum + rhs[i + 1]);
	}
	return res;
}

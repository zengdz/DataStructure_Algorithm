/*
 * 有一个X*Y的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。
 * 给定两个正整数int x,int y，且保证x＋y小于等于12。计算有多少种走法。
 */
#include <iostream>
#include <vector>

using namespace std;

// 递归式的目标值为 countWays(x,y)
// 机器人走格点对于1*Y或者X*1而言分别是竖线和横线，只有一种走法
int countWays(int x, int y) {
	if (x == 1 || y == 1)
		return 1;
	// 分别对应往右走和向下走的两种情况
	return countWays(x - 1, y) + countWays(x, y - 1);
}

// 递归转动态规划：目标值和两个状态有关，所以是二维表
// 确定基础状态，以及范围：[0~x-1]和[0~y-1]
int countWays(int x, int y) {
	if (x < 1 || y < 1)
		return 0;
	if (x == 1 || y == 1)
		return 1;
	vector<vector<int>> dp(x, vector<int>(y));
	for (int i = 0; i < x; ++i)
		dp[i][0] = 1;
	for (int j = 0; j < y; ++j)
		dp[0][j] = 1;
	for (int i = 1; i < x; ++i) {
		for (int j = 1; j < y; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	return dp[x-1][y-1];
}
int main()
{
	cout << countWays(3,9) << endl;

	return 0;
}

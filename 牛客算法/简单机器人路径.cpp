/*
 * 有一个X*Y的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。
 * 给定两个正整数x和y，且保证x＋y小于等于12。计算有多少种走法。
 */
#include <iostream>
#include <vector>

using namespace std;

// 递归式的目标值为 countWays(x,y)
// 机器人走格点对于1*Y或者X*1而言分别是竖线和横线，只有一种走法
int countWaysRecur(int x, int y) {
	if (x < 1 || y < 1)
		return 0;
	if (x == 1 || y == 1)
		return 1;
	// 分别对应往右走和向下走的两种情况，注意X,Y不要视为坐标！
	// 而是网格的线条数。往右走则X的线条数减1，往下走则Y的线条数减1
	return countWaysRecur(x - 1, y) + countWaysRecur(x, y - 1);
}

// 递归转动态规划：目标值和两个变量有关，所以是二维表
int countWays(int x, int y) {
	if (x < 1 || y < 1)
		return 0;
	// 为了易于理解，维度加1使得结果刚好就是对应坐标值
	// 如果是dp[x][y]那么返回的是dp[x-1][y-1]
	vector<vector<int>> dp(x + 1, vector<int>(y + 1));
	for (int i = 1; i <= x; ++i)
		dp[i][1] = 1;
	for (int j = 1; j <= y; ++j)
		dp[1][j] = 1;

	for (int i = 2; i <= x; ++i) {
		for (int j = 2; j <= y; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[x][y];
}

// 通过动态规划的画图分析，发现每一轮只有两个数组在演算
// 所以可以只创建少量数组，然后通过数组滚动计算得出目标值
// 本题两演算数组紧挨着，所以最少只需要2个辅助数组
int countWaysSpaceCompress(int x, int y) {
	if (x < 1 || y < 1)
		return 0;
	// import! 空间压缩时，初值条件一定要判断
	// 因为不像未压缩数组那样会保留，压缩时数组滚动会修改
	if (x == 1 || y == 1)
		return 1;
	// 同样为了便于理解，空间分配多了1
	vector<vector<int>> dp(3, vector<int>(y + 1));
	dp[2][1] = 1; // 这个位置在滚动过程不会变，一直是1
	// 第一个数组的值全是已知的
	for (int j = 1; j <= y; ++j)
		dp[1][j] = 1;
	
	for (int i = 2; i <= x; ++i) {
		// 根据要求计算第二个数组的值
		for (int j = 2; j <= y; ++j) {
			dp[2][j] = dp[1][j] + dp[2][j - 1];
		}
		// 滚动过程，把第二个数组值给第一个数组
		for (int j = 2; j <= y; ++j) {
			dp[1][j] = dp[2][j];
		}
	}
	return dp[2][y];
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << countWaysRecur(x, y) << endl; // 递归法
	cout << countWays(x, y) << endl; // 常规动态规划
	cout << countWaysSpaceCompress(x, y) << endl; // 基于空间压缩的动态规划

	return 0;
}

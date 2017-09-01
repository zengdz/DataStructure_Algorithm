/*
 * 给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多
 * 编写程序求组成N元（N为0-10000的非负整数）的不同组合的个数
 */
#include <iostream>
#include <vector>

using namespace std;

int money[] = { 1, 5, 10, 20, 50, 100 };

// n是需要换的钱数，m是硬币的种数
long changeWayRecur(int n, int m) {
	if (n == 0) 
		return 1; // 规定0元有1种换法
	if (n < 0 || m == 0) 
		return 0; // 小于0元或者没有硬币则没法换即0种换法

	// 分解两种情况：使用某种硬币时的种数；不使用某种硬币时的种数
	return changeWayRecur(n, m - 1) + changeWayRecur(n - money[m - 1], m);
}

// 如果把硬币种数当作一个变量，dp需要二维向量
long changeWayDP(int n, int m) {
	if (n == 0) return 1;
	if (n < 0 || m == 0) return 0;
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= m; ++i)
		dp[i][0] = 1;
	for (int j = 1; j <= n; ++j)
		dp[0][j] = 0;
	// 根据递归式以及画图分析，使用两个循环计算dp[i][j]
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i - 1][j];
			// 递归式中有个区间判断，所以迭代时对应有个判断钱数n是否小于0
			// 递归中money[m - 1]和本处money[i - 1]含义不同，表达式却一致
			// 这里的判断对应的是递归初始判断的 n<0 情况，可以改成if，如果大于等于0就加
			//dp[i][j] += ((j - money[i - 1]) < 0) ? 0 : dp[i][j - money[i - 1]];
			if (j - money[i - 1] >= 0)
				dp[i][j] += dp[i][j - money[i - 1]];
		}
	}
	return dp[m][n];
}

// 因为硬币种类是有限的，如果把硬币种类视作常量，只需一维向量
// 递归中不使用某种硬币，通过遍历每种硬币来处理，实现变量转常量
long changeWayDP_2(int n, int m) {
	if (n == 0) return 1;
	if (n < 0 || m == 0) return 0;
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			// 优化：既然要求j-money[i]>=0，可在循环初值j=money[i]，然后循环体不用再判断
			if (j - money[i] >= 0)
				// 一旦m视作常量，递归式右边第一项和左边就相同了
				// 左边dp[j]要先等于右一dp[j]在if判断后再和右二相加
				// 因为前两个相等，可以全都放在判断后。也使得上面的优化可行
				dp[j] = dp[j] + dp[j - money[i]];
		}
	}
	return dp[n];
}

int main()
{
	int num;
	cin >> num;
	cout << changeWayRecur(num, 6) << endl;
	cout << changeWayDP(num, 6) << endl;
	cout << changeWayDP_2(num, 6) << endl;

	return 0;
}

/*
 * 题目：如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？
 * (表面上这道题可以用贪心算法，但贪心算法无法保证可以求出解，比如1元换成2元的时候)
 */
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// coins代表零钱类目，n代表要凑的钱数
int changeWayMin(vector<int> &coins, int n) {
	if (coins.empty() || n < 0)
		return -1;
	// dp[i]表示凑数值为i的钱最少需要的硬币数
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < coins.size() ; ++j) {
			// 怎么用代码体现找的零钱数是最少？人是通过找面值大的先换
			// 机器是遍历比较，比较每种硬币换了之后用最少数量的那个
			if (i >= coins[j]){ // 要大于面值才能换
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);	
			}
		}
	}
	return dp[n];
}
 
int main() 
{
	vector<int> money = { 1, 3, 5 }; // 分别是1,3,5元
	int num;
	cin >> num;
	cout << changeWayMin(money, num) << endl;
	
	return 0;
}

/*
 * 题目：如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？
 * (表面上这道题可以用贪心算法，但贪心算法无法保证可以求出解，比如1元换成2元的时候)
 */
#include<stdio.h>
#include <iostream>

using namespace std;

// coins代表零钱类目，target代表要凑的钱数
int min_coin(const int *coins, const int target)
{
	if (coins == nullptr || target < 0)
		return -1;
	// Min[i]表示凑数值为i的钱最少需要的硬币数，此为状态
	// 数组第0元素为0，因为凑0元不需要硬币。然后其余元素为可能的最大值
	// 因为最小面额为1，那么凑的钱数如果用1元凑需要硬币数最多。或者全都设为很大的数比如1000
	int Min[14] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	for (int i = 1; i <= target; ++i) {
		// int num_of_coins = sizeof(coins)/sizeof(coins[0]); 
		// 一直得不到正确结果，调试发现num_of_coins计算得到1，正常应该是3
		// 立马想到因为数组名退化为指针，导致4/4=1
		// 数字3代表零钱种类的数目
		for (int j = 0; j < 3; ++j) {
			// 状态转移过程
			if (i >= coins[j] && ((Min[i - coins[j]] + 1) < Min[i])) {
				Min[i] = Min[i - coins[j]] + 1;
			}
		}
	}
	return Min[target];
}
 
int main() {
	int money[] = { 1, 3, 5 }; // 分别是1,3,5元

	// 输出凑的钱数为0-13时分别需要的最少硬币数
	for (int num = 0; num < 14; ++num) {
		int res = min_coin(money, num);
		cout << num << " : " <<res << endl;
	}
}

/*
 * 题目：求1~n这n个整数的十进制表示中1出现的次数
 */
#include <iostream>
#include <vector>

using namespace std;

// 计算一个正整数中数字1的个数
// 依次计算最低位是否为1
int NumberOf1(unsigned int n)
{
	int num = 0;
	while (n) {
		if (n % 10 == 1)
			++num;
		n /= 10;
	}
	return num;
}

int NumberOf1Between1AndN_Solution(int n)
{
	int ones = 0;
	for (int i = 1; i <= n; ++i)
		ones += NumberOf1(i);
	return ones;
}

// 对数字分析简洁版，待处理
int NumberOf1Between1AndN(int n)
{
	int ones = 0;
	for (long long m = 1; m <= n; m *= 10)
		ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n%m + 1);
	return ones;
}

int main()
{
	vector<int> numbers = { 1,-2,3,10,-4,7,2,-5 };

	cout << NumberOf1Between1AndN(12) << endl;

	return 0;
}

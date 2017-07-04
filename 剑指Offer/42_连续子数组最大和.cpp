/*
 * 题目：一个含有正负数的整型数组，求所有(连续)子数组的和的最大值
 * 要求时间复杂度为O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.empty())
		return 0;
	int GreatSum = 0x80000000; // 这是int可以表示的最大负数
	int CurSum = 0; // 当前子数组和初始化为0
	for (auto i : array) {
		// 如果当前和小于等于0那么加上下一个数字只会没有影响或者负增长
		// 所以舍弃前面的以新的数字当作开始
		if (CurSum <= 0)
			CurSum = i;
		// 否则就加上新的数字
		else
			CurSum += i;
		// CurSum随着新的数字添加而变化，更新最大和
		if (CurSum > GreatSum)
			GreatSum = CurSum;
	}
	return GreatSum;
}

int main()
{
	vector<int> numbers = { 1,-2,3,10,-4,7,2,-5 };
	cout << FindGreatestSumOfSubArray(numbers) << endl;

	return 0;
}

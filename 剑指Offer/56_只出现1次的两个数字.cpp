/*
 * 题目：整型数组中除2个数字之外，其他数字都出现了2次，找出这2个只出现一次的数字
 * 要求时间复杂度O(n)，空间复杂度O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

// 找出整数的二进制表示中第一次出现1的位置(从低位开始)
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while ((num & 0x01) == 0 && indexBit < 8 * sizeof(int)) {
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

// 要返回两个数字只能作为参数传递
void FindNumsAppearOnce(vector<int> data, int& num1, int& num2)
{
	if (data.empty())
		return;
	int resXOR = 0; // 异或结果
	for (auto i : data)
		resXOR ^= i;
	auto index = FindFirstBitIs1(resXOR);
	num1 = num2 = 0;
	for (auto i : data) {
		// 根据数字的对应位是否为1，分为两拨进行异或操作
		if ((i >> index) & 0x01)
			num1 ^= i;
		else
			num2 ^= i;
	}
}

int main()
{
	vector<int> numbers = { 2,4,3,6,3,2,5,5 };
	int num1, num2;
	FindNumsAppearOnce(numbers, num1, num2);
	cout << num1 << " " << num2 << endl;

	return 0;
}

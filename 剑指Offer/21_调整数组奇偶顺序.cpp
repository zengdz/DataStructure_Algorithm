/*
 * 题目：调整一个整数数组中数字顺序，使得所有奇数在前半部分，而偶数位于后半部分
 * 方法一和快速排序的机制是一样的，都是要按照某个规则去调整元素位置
 * 方法二可以保证元素相对位置不变，用冒泡排序的思路
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 只能保证奇数在前偶数在后，不能保证相对位置不变！
// 时间复杂度O(n),空间O(1)
void reOrderArray(vector<int> &array)
{
	if (array.empty())
		return;
	int begin = 0;
	int end = array.size() - 1;
	while (begin < end) {
		// 如果遇到奇数就左边递增直到遇到偶数为止
		while (begin < end && (array[begin] & 0x01) != 0)
			++begin;
		// 如果遇到偶数就右边递减直到遇到奇数为止
		while (begin < end && (array[end] & 0x01) == 0)
			--end;
		// 如果偶数在左边而奇数在右边，则交换
		if (begin < end)
			swap(array[begin], array[end]);
	}
}

// 用冒泡排序的思路，保证元素相对位置不变
void reOrderArrayBubble(vector<int> &array)
{
	if (array.empty())
		return;
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = array.size() - 1; j > i; j--)
		{
			if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
			{
				swap(array[j], array[j - 1]);
			}
		}
	}
}

// 使用string类传递输出信息
// 因为向量是迭代的，使用for范围语句遍历元素
void PrintVector(const string info, const vector<int>& arr)
{
	cout << info;
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> arr1 = {1,2,3,4,5};
	vector<int> arr2 = { 1,2,3,4,5 };
	PrintVector("Former vector: ", arr1);
	reOrderArray(arr1);
	PrintVector("Changed vector1: ", arr1);
	reOrderArrayBubble(arr2);
	PrintVector("Changed vector2: ", arr2);

	return 0;
}

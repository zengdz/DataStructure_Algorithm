/*
 * 排序数组的二分法应用举一反三：找下标不相等位置或者找下标和数据相等
 * 题目1：长度n-1递增排序数组所有数字唯一，每个数组在0~n-1范围，仅有一个数字缺失，找出它
 * 题目2：单调递增数组元素是整数且唯一，找出任意一个数值等于其下标的元素
 */
#include <iostream>
#include <vector>

using namespace std;

// 找第一个下标和数值不相等的位置就是缺失的数字
int FindMissingNumber(vector<int> num)
{
	if (num.empty()) 
		return -1;
	int length = num.size();
	int low = 0;
	int high = length - 1;
	while (low <= high) {
		int mid = low + ((high - low) >> 1);
		// 如果索引和数值不相等，还要判断是不是第一个不相等的
		if (num[mid] != mid) {
			// 注意边界情况，mid为0时单独处理，否则num[mid-1]越界
			// 如果左边元素和索引相同，说明这是第一个位置和数值不相等
			if (mid == 0 || num[mid - 1] == mid - 1)
				return mid;
			// 否则不是第一个不相等的，还要往左边找
			high = mid - 1;
		}
		// 如果索引和数值相等，左边肯定都相等，往右边找
		else
			low = mid + 1;
	}
	// 如果全部都相等，说明缺的是最后一个
	if (low == length)
		return length;
	// 数组不是排序，数字不在0-n-1范围
	// 没有缺失的数字
	return -1;
}

// 单调递增数组中找出任意一个数值等于其下标的元素
int GetNumSameAsIndex(vector<int> num)
{
	if (num.empty()) 
		return -1;
	int low = 0;
	int high = num.size() - 1;
	while (low <= high) {
		int mid = low + ((high - low) >> 1);
		// 如果数字大于索引，由于数组是单调递增
		// 后面的元素只会大于索引，所以只能往左边找
		if (num[mid] > mid)
			high = mid - 1;
		// 如果数字小于索引，前面的元素只会小于索引，只能往右边找
		else if (num[mid] < mid)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	vector<int> num1 = {1,2,3,4,5,6,7,8,9}; // 少了数字0
	vector<int> num2 = {0,1,2,3,4,5,7,8,9}; // 少了数字6
	vector<int> num3 = {0,1,2,3,4,5,6,7,8}; // 少了数字9
	vector<int> num4 = { }; // 空向量
	cout << "Missing number is: " << FindMissingNumber(num1) << endl;
	cout << "Missing number is: " << FindMissingNumber(num2) << endl;
	cout << "Missing number is: " << FindMissingNumber(num3) << endl;
	cout << "Missing number is: " << FindMissingNumber(num4) << endl;

	vector<int> Num1 = {0,2,4,11,13}; // 数字0在位置0
	vector<int> Num2 = {-3,-1,1,3,5}; // 数字3在位置3
	vector<int> Num3 = {-3,-1,1,2,4}; // 数字4在位置4
	vector<int> Num4 = {-3,-1,1,2,6}; // 不存在数字和索引相同
	cout << "Same as idex is: " << GetNumSameAsIndex(Num1) << endl;
	cout << "Same as idex is: " << GetNumSameAsIndex(Num2) << endl;
	cout << "Same as idex is: " << GetNumSameAsIndex(Num3) << endl;
	cout << "Same as idex is: " << GetNumSameAsIndex(Num4) << endl;

	return 0;
}

/*
 * 二分查找法变体：如果排序数组含有重复的数字，该输出哪个？
 * 可根据需求进行查找，比如查找重复数据第一次出现或者最后一次出现的位置
 */

#include <stdio.h>
#include <iostream>

using namespace std;

// 正常版本，如果被查找的数据不唯一，不确定输出的是哪个
int BinarySearch(int *a, int length, int key) {
	if (a == nullptr || length < 1)
		return -1;
	int low = 0;
	int high = length - 1;

	while (low <= high) {
		// 注意下面的移位一定要加括号，右移优先级比加法低！
		int mid = ((high - low) >> 1) + low; // (low+high)/2 方式有溢出风险		
		if (key > a[mid])
			low = mid + 1;
		else if (key < a[mid])
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

// 找第一次出现数据的位置
// 兼容正常版本，对不重复的数组仍有效
int BinarySearch_FirstOccur(int *a, int length, int key) {
	if (a == nullptr || length < 1)
		return -1;
	int low = 0;
	int high = length - 1;
	int res = -1; // 结果变量，如果没找到就是-1，否则被查找结果覆盖

	while (low <= high) {
		int mid = ((high - low) >> 1) + low;	
		if (key > a[mid])
			low = mid + 1;
		else if (key < a[mid])
			high = mid - 1;
		else {
			// 把找到的保存起来，然后继续往前寻找
			res = mid;
			high = mid - 1;
		}
	}
	return res; // 如果没有找到，返回默认值-1
}

// 找最后一次出现数据的位置
// 兼容正常版本，对不重复的数组仍有效
int BinarySearch_LastOccur(int *a, int length, int key) {
	if (a == nullptr || length < 1)
		return -1;
	int low = 0;
	int high = length - 1;
	int res = -1;

	while (low <= high) {
		int mid = ((high - low) >> 1) + low;
		if (key > a[mid])
			low = mid + 1;
		else if (key < a[mid])
			high = mid - 1;
		else {
			// 把找到的保存起来，然后继续往后寻找
			res = mid;
			low = mid + 1;
		}
	}
	return res;
}

int main(){
	int a[] = {0,1,2,3,3,3,4,5,9};
	int length = sizeof(a) / sizeof(a[0]);

	// 查找存在重复的数据，结果不一
	cout << BinarySearch(a, length, 3) << endl;
	cout << BinarySearch_FirstOccur(a, length, 3) << endl;
	cout << BinarySearch_LastOccur(a, length, 3) << endl;

	// 查找不重复的数据，结果一致
	cout << BinarySearch(a, length, 4) << endl;
	cout << BinarySearch_FirstOccur(a, length, 4) << endl;
	cout << BinarySearch_LastOccur(a, length, 4) << endl;
	
	return 0;
}

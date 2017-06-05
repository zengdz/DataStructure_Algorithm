#include <stdio.h>
#include <iostream>
//#define OPENAREA // 取消注释使用开区间版本，注释掉则使用常规闭区间版本
using namespace std;
 
#ifdef OPENAREA
// 左闭右开的区间情况
int BinarySearch(int *a, int length, int key){
	if (a == nullptr || length < 1)
		return -1;
	int low = 0;
	int high = length;

	while(low != high){
		// 注意下面的移位一定要加括号，右移优先级比加法低！
		int mid = ((high - low) >> 1) + low; // (low+high)/2 方式有溢出风险
		if(key > a[mid])
			low = mid + 1;
		else if(key < a[mid])
			high = mid; // 由于右边开区间，所以不用 mid-1
		else
			return mid;
	}
	return -1;
}
#else
// 左闭右闭的区间情况
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
#endif

// 二分查找闭区间--递归版本，形参需要指明上下限
int bin_search_recursive(int arr[], int lhs, int rhs, int key)
{
	if (arr == nullptr || lhs > rhs || rhs < 0)
		return -1;

	// 注意：递归版本这里是if不是while
	// 递归依靠终止条件来结束递归过程
	if (lhs <= rhs) {
		int mid = lhs + ((rhs - lhs) >> 1);
		if (arr[mid] > key)
			return bin_search_recursive(arr, lhs, mid - 1, key);
		else if (arr[mid] < key)
			return bin_search_recursive(arr, mid + 1, rhs, key);
		else
			return mid;
	}
	return -1;
}

int main(){
	int a[] = {0,1,2,3,4,5,9};
	int length = sizeof(a) / sizeof(a[0]);

	// 迭代版本
	cout << "Iterative implementation of Binary Search:" << endl;
	cout << BinarySearch(a, length, 0) << endl; // 查找第一个值
	cout << BinarySearch(a, length, 9) << endl; // 查找最后一个值
	cout << BinarySearch(a, length, 3) << endl; // 查找中间值
	cout << BinarySearch(a, length, 13) << endl; // 查找不存在的值
	cout << BinarySearch(nullptr, length, 9) << endl; // 测试空指针
	cout << BinarySearch(a, 0, 9) << endl; // 测试长度参数为0

	// 递归版本
	cout << "Recursive implementation of Binary Search:" << endl;
	cout << bin_search_recursive(a, 0, length - 1, 0) << endl;
	cout << bin_search_recursive(a, 0, length - 1, 9) << endl;
	cout << bin_search_recursive(a, 0, length - 1, 3) << endl;
	cout << bin_search_recursive(a, 0, length - 1, 13) << endl;
	cout << bin_search_recursive(nullptr, 0, length - 1, 9) << endl;
	cout << bin_search_recursive(a, 3, 2, 0) << endl; // 测试左边索引比右边大

	return 0;
}

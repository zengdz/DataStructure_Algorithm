/*
 * 旋转数组查找最小元素或者旋转次数(可处理含有重复数字情况)
 * 最小元素的位置就是旋转数组的旋转次数
 * 如果只是问最小元素，不顾给的条件和效率，把数组排序取第一个就是结果
 */
#include <iostream>
using namespace std;

// 在数组arr的区间[idx1,inx2]中顺序查找最小值
// 函数返回查找到的最小值
int MinInOrder(int arr[], int idx1, int idx2)
{
	int res = arr[idx1];
	for (int i = idx1 + 1; i <= idx2; ++i) {
		if (arr[i] < res)
			res = arr[i];
	}
	return res;
}

int FindMin_RorateArr(int arr[], int length)
{
	if (arr == nullptr || length < 1)
		return -1;
	int idx1 = 0;
	int idx2 = length - 1;
	int idxMid = idx1; // 如果数组有序则返回第一个元素

	while (arr[idx1] >= arr[idx2]) {
		// 当idx1和idx2距离为1时，idx1指向左边递增数组最后一个
		// idx2指向右边递增数组的第一个，所以此时idx2指向最小值
		if (idx2 - idx1 == 1)
			return arr[idx2];
		idxMid = idx1 + ((idx2 - idx1) >> 1);
		// 如果两边和中间元素相同，则无法判断中间元素是在哪边
		// 在该区间使用顺序查找并返回最小值作为结果
		if (arr[idx1] == arr[idxMid] && arr[idx2] == arr[idxMid])
			return MinInOrder(arr, idx1, idx2);
		// 如果中间元素大于左边，说明中间元素在左边，缩减左边范围
		if (arr[idxMid] >= arr[idx1])
			idx1 = idxMid;
		// 如果中间元素小于右边，说明中间元素在右边，缩减右边范围
		else if (arr[idxMid] <= arr[idx2])
			idx2 = idxMid;
	}
	return arr[idxMid];
}

int main()
{
	int arr1[] = { 3, 4, 5, 1, 2 };
	int arr2[] = { 3, 4, 5, 1, 1, 2 };
	int arr3[] = { 1, 0, 1, 1, 1 };
	int arr4[] = { 1, 2, 3, 4, 5 };
	int arr5[] = { 2 };

	cout << FindMin_RorateArr(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	cout << FindMin_RorateArr(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl;
	cout << FindMin_RorateArr(arr3, sizeof(arr3) / sizeof(arr3[0])) << endl;
	cout << FindMin_RorateArr(arr4, sizeof(arr4) / sizeof(arr4[0])) << endl;
	cout << FindMin_RorateArr(arr5, sizeof(arr5) / sizeof(arr5[0])) << endl;
	cout << FindMin_RorateArr(NULL, sizeof(arr5) / sizeof(arr5[0])) << endl;

	return 0;
}

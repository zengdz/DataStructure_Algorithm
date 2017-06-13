/*
 * 旋转数组（不含重复元素）查找最小元素或者旋转次数
 * 或者在旋转数组中查找某个元素在数组中的位置
 * 注意本程序不适用于含有重复数据的旋转数组
 */
#include <iostream>

using namespace std;

// 最小元素的位置就是旋转的次数
int FindRotationCount(int a[], int n)
{
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		// Case1: 如果左边小于右边说明没有旋转
		// 那么第一个元素就是最小元素，数组旋转0次
		if (a[low] <= a[high])
			return low;
		int mid = low + ((high - low) >> 1);
		// 注意边界情况即mid在两端时
		int prev = (mid + n - 1) % n;
		int next = (mid + 1) % n;
		// Case2: 刚好找到那个最小值，它不大于两边元素
		if (a[mid] <= a[prev] && a[mid] <= a[next])
			return mid;
		// Case3: 如果中间元素小于右端元素，说明在右半边
		// 最小值则在左边，把右边范围缩小
		else if (a[mid] <= a[high])
			high = mid - 1;
		// Case4: 如果中间元素大于右端元素，说明在左半边
		// 最小值则在右边，把左边范围缩小
		else if (a[mid] >= a[high])
			low = mid + 1;
	}
	return -1;
}

// 在旋转数组中查找某个元素
int CircularArraySearch(int a[], int n, int x)
{
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = low + ((high - low) >> 1);
		if(x == a[mid])
			return mid;
		// 中间元素位于右边有序数组中
		if (a[mid] <= a[high]) {
			// 若被查找元素在右侧
			if (x > a[mid] && x <= a[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
		// 中间元素位于左边有序数组中
		else{
			// 若被查找元素在左侧
			if (x >= a[low] && x < a[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}		
	}
	return -1;
}

int main()
{
	int a1[] = {1,2,3,4,5,6}; // 未旋转
	int a2[] = {4,5,6,1,2,3}; // 旋转部分
	int a3[] = {2,3,4,5,6,1}; // 完全旋转

	int length = sizeof(a1) / sizeof(a1[0]);

	cout << FindRotationCount(a1, length) << endl; // 未旋转，输出0
	cout << FindRotationCount(a2, length) << endl; // 旋转3次，输出3
	cout << FindRotationCount(a3, length) << endl; // 旋转5次，输出5

	cout << CircularArraySearch(a2, length, 4) << endl; // 查找第一个
	cout << CircularArraySearch(a2, length, 3) << endl; // 查找最后一个
	cout << CircularArraySearch(a2, length, 6) << endl; // 查找中间
	cout << CircularArraySearch(a2, length, 9) << endl; // 查找不存在元素

	return 0;
}

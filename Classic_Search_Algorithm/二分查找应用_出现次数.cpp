/*
 * 在一个排序重复的数组里面找某个数出现的次数
 * 既然排序则可以采用二分查找，如果存在重复又排序那么重复元素必然连续
 * 根据二分查找的变体找出最后一次和第一次出现的位置，就可以计算出次数
 */

#include <iostream>

using namespace std;

// 找第一次出现和最后一次出现的代码只有一行不同
// 可以不用分别写一个函数，而是形参加一个参数来控制
// 前三个参数和正常二分查找相同，最后一个参数若为真查找第一个，否则查找最后一个
int BinSearch_FirstLast(int a[], int n, int x, bool FirstSearch)
{
	int low = 0;
	int high = n - 1;
	int res = -1;
	while(low <= high){
		int mid = low + ((high - low) >> 1);
		if(a[mid] > x)
			high = mid - 1;
		else if(a[mid] < x)
			low = mid + 1;
		else
		{
			res = mid;
			if (FirstSearch)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return res;
}

int FindCount(int a[], int n, int x)
{
	if(a == nullptr)
		return -1;
	// 要判断是否找到，若没找到则返回0
	// 如果不处理，最后结果返回错误的结果1（-1减-1加1）
	if (BinSearch_FirstLast(a, n, x, true) == -1)
		return 0;
	else
		return (BinSearch_FirstLast(a, n, x, false) - BinSearch_FirstLast(a, n, x, true) + 1);
}

int main()
{
	int a[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6};
	int length = sizeof(a) / sizeof(a[0]);

	cout << FindCount(a, length, 1) << endl; // 出现1次
	cout << FindCount(a, length, 5) << endl; // 出现多次
	cout << FindCount(a, length, 7) << endl; // 未出现
	cout << FindCount(0, length, 7) << endl; // 异常参数

	return 0;
} 

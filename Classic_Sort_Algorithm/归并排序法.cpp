/* 
 * 基础算法--归并排序
 * 归并排序的最好、最坏和平均时间复杂度都是O(nlogn)，而空间复杂度是O(n)
 * 2017/6/4 SAIL@DG
 */
#include <stdio.h>
#include <iostream>

using namespace std;

// 合并两个有序子数组 arr[lhs,mid]和 arr[mid+1,rhs]
// 需要一个临时数组保存合并排序的结果，最后再把临时数组拷贝到原数组
// 尝试在原数组进行原地逆向合并，这样空间复杂度就是O(1)，但实现不了！
// 所以还是要用辅助空间，空间长度不确定，使用malloc或者new创建动态数组
// 由于是用辅助空间合并有序数组(递归形成有序)，从前往后和逆向效果一样。
void merge(int arr[], int lhs, int mid, int rhs)
{
	int length = rhs - lhs + 1;
	int *temp = new int[length];
	int temp_idx = 0;
	int l_idx = lhs;
	int r_idx = mid + 1;

	// 进行元素比较，只有在两边都有元素时才能比较
	// 所以只要有一边先完成就结束
	while (l_idx <= mid && r_idx <= rhs) {
		if (arr[l_idx] <= arr[r_idx])
			temp[temp_idx++] = arr[l_idx++];
		else
			temp[temp_idx++] = arr[r_idx++];
	}

	// 把剩余元素直接移动到辅助数组后面
	// 其实不用判断到底是哪边有剩下元素
	// 只有在数组有剩下元素情况下，其索引才能满足while循环条件
	while (l_idx <= mid) 
		temp[temp_idx++] = arr[l_idx++];
	while (r_idx <= rhs)
		temp[temp_idx++] = arr[r_idx++];

	// 把辅助数组的结果移动到原数组的对应位置
	for (int i = 0; i < length; ++i) {
		// 之前误写为 arr[lhs + i] = temp[i++]; 
		arr[lhs + i] = temp[i];
	}

	delete[] temp;
}

void MergeSort(int arr[], int lhs, int rhs)
{
	if (arr == nullptr || lhs >= rhs || rhs < 0)
		return;

	if (lhs < rhs) {
		// 持续划分数组，直到 lhs = rhs 导致不可划分
		int mid = lhs + ((rhs - lhs) >> 1);
		MergeSort(arr, lhs, mid);
		MergeSort(arr, mid + 1, rhs);

		// 把划分的每一组分组进行合并
		merge(arr, lhs, mid, rhs);
	}
}

// 输出结果函数，带一个字符串参数用于输出提示信息
// 然后是被输出的数组以及数组的长度，都是输出内容所以const修饰
void PrintResult(const char *s, const int arr[], const int length)
{
	cout << s << endl;
	for (int i = 0; i < length; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[]={8,2,5,4,5,7,3,13,23,8,21,66,33};
	int length = sizeof(arr) / sizeof(arr[0]);

	PrintResult("Formal Array:", arr, length);

	MergeSort(arr, 0, length - 1);

	PrintResult("Merge Sort Result:", arr, length);

	return 0;
}

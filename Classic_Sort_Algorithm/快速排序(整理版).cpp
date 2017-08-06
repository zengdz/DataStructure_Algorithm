/*
 * 基础算法--快速排序
 * 归并排序的时间复杂度：最好O(nlogn),最坏O(n^2),平均O(nlogn)
 * 空间复杂度：最优O(logn)，最坏O(n)
 * 采用向量替代数组，分离Partition函数
 * 2017/8/6 SAIL@DG
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Partition(vector<int> &arr, int i, int j) {
	int key = arr[i];
	while (i < j) {
		while (i < j && arr[j] >= key)
			--j;
		swap(arr[i], arr[j]);
		while (i < j && arr[i] <= key)
			++i;
		swap(arr[i], arr[j]);
	}
	return i;
}

void QuickSort(vector<int> &arr, int low, int high)
{
	if (arr.empty() || low > high || high < 0)
		return;
	if (low < high) {
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
	}
}

void PrintArrayResult(const string s, vector<int> arr, const int length)
{
	cout << s << endl;
	for (int i = 0; i < length; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() 
{
	vector<int> arr = { 8,2,5,4,5,7,3,13,23,8,21,66,33,8 };
	int length = arr.size();
	PrintArrayResult("Formal unsorted array:", arr, length);

	QuickSort(arr, 0, length - 1);

	PrintArrayResult("Quick sort result:", arr, length);

	return 0;
}

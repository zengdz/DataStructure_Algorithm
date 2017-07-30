/*
 * 逆序对和小数和都是根据归并函数改写的
 * 逆序对：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对
 * 小数和：定义为所有元素i的f(i)值之和。这里的f(i)函数定义为元素i左边(不包括其自身)小于等于它的数字之和
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int InversePair_MergeSort(vector<int> &data, int start, int end)
{
	if (start == end)
		return 0;
	int mid = start + ((end - start) >> 1);
	int LeftCnt = InversePair_MergeSort(data, start, mid);
	int RightCnt = InversePair_MergeSort(data, mid + 1, end);

	vector<int> temp(data);
	int i = start;
	int j = mid + 1;
	int TempIdx = start;
	int cnt = 0;
	while (i <= mid && j <= end) {
		if (data[i] > data[j]) {
			temp[TempIdx++] = data[j++];
			// 如果左边第一个元素大于右边，那么左边所有元素都将大于右边
			// 逆序对的个数就是左边元素的数量
			cnt += mid - i + 1;
		}
		else
			temp[TempIdx++] = data[i++];
	}
	while (i <= mid)
		temp[TempIdx++] = data[i++];
	while (j <= end)
		temp[TempIdx++] = data[j++];
	// 如果数据量很大，每次的赋值会消耗很多时间
	// 剑指Offer上有个技巧：把辅助向量加入形参，然后递归时交换辅助向量和原向量
	for (int i = start; i <= end; i++)
		data[i] = temp[i];
	return (LeftCnt + RightCnt + cnt);
}

int InversePairs(vector<int> data)
{
	if (data.empty())
		return 0;
	return InversePair_MergeSort(data, 0, data.size() - 1);
}
/********************************************************************************/

// 注意形参向量的引用，函数需要修改向量
int merge(vector<int> &s, int left, int mid, int right) {
	vector<int> h(right - left + 1);
	int hi = 0; // 辅助数组的索引
	int i = left;
	int j = mid + 1;
	int smallSum = 0;
	while (i <= mid && j <= right) {
		if (s[i] <= s[j]) {
			// merge函数增加的一行
			// 如果左边元素比右边最小元素小，那么小数和为右边元素个数乘以该左边元素
			smallSum += s[i] * (right - j + 1);
			h[hi++] = s[i++];
		}
		else {
			h[hi++] = s[j++];
		}
	}
	for (; (j < right + 1) || (i < mid + 1); j++, i++) {
		h[hi++] = i > mid ? s[j] : s[i];
	}
	for (int k = 0; k != h.size(); k++) {
		s[left++] = h[k];
	}
	return smallSum;
}
// 注意形参向量的引用，函数需要修改向量
int func(vector<int> &s, int l, int r) {
	if (l == r) {
		return 0;
	}
	int mid = (l + r) / 2;
	return func(s, l, mid) + func(s, mid + 1, r) + merge(s, l, mid, r);
}

int getSmallSum(vector<int> arr) {
	if (arr.empty())
		return 0;
	return func(arr, 0, arr.size() - 1);
}

int main() 
{
	vector<int> arr = { 3, 1, 2, 4, 6, 2, 7, 8, 1 };
	cout << getSmallSum(arr) << endl;

	vector<int> inversePair = { 7,5,6,4 };
	cout << InversePairs(inversePair) << endl;

	return 0;
}

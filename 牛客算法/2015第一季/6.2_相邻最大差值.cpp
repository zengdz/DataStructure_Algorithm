/*
 * 设计一个复杂度为O(n)的算法，计算一个未排序数组中排序后相邻元素的最大差值。
 * 给定一个整数数组A和数组的大小n，请返回最大差值。保证数组元素个数大于等于2小于等于500
 * 示例：[9,3,1,10],4 返回6
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// 计算某个元素在桶中的索引
int getIndex(int num, int min, int max, int length) {
	return (num - min) * length / (max - min);
}

int findMaxDivision(vector<int> A, int n) {
	if (A.empty() || n < 2)
		return 0;
	int theMax = INT_MIN;
	int theMin = INT_MAX;
	// 先找出给定数组的最大最小值
	for (auto i : A) {
		theMax = max(theMax, i);
		theMin = min(theMin, i);
	}
	// 如果最大值和最小值相等，所有元素相等则差值为0
	if (theMax == theMin)
		return 0;
	// 创建三个(n+1)大小的桶，分别表示：区间最大值；区间最小值；区间是否空
	vector<int> maxBucket(n + 1);
	vector<int> minBucket(n + 1);
	vector<bool> validBucket(n + 1);
	for (int i = 0; i < n; ++i) {
		int idx = getIndex(A[i], theMin, theMax, n); // 获得区间索引
		if (validBucket[idx]) { // 如果该索引区间有数，更新最大最小值
			maxBucket[idx] = max(maxBucket[idx], A[i]);
			minBucket[idx] = min(minBucket[idx], A[i]);
		}
		else { // 否则给三个桶赋初值
			maxBucket[idx] = A[i];
			minBucket[idx] = A[i];
			validBucket[idx] = true;
		}
	}
	int maxDivision = INT_MIN; // 最大差值
	int i = 0; // 循环外的变量(针对后面2个for循环的全局变量)
	int lastMax = 0;
	for (; i <= n; ++i) {
		if (validBucket[i]) { // 找第一个区间不为空的最大值
			lastMax = maxBucket[i];
			break; // 结束循环
		}
	}
	// 找其他不为空的区间，新区间最小值减去上一次的最大值就是相邻差值
	// 更新差值的最大值
	for (; i <= n; ++i) {
		if (validBucket[i]) {
			maxDivision = max(maxDivision, minBucket[i] - lastMax);
			lastMax = maxBucket[i];
		}
	}
	return maxDivision;
}

int main()
{
	vector<int> arr = {9,3,1,10};
	cout << findMaxDivision(arr, arr.size()) << endl;

	return 0;
}

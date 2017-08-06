/*
 * 题目：数组中有个数字出现的次数超过数组长度的一半，找出该数字
 * 如果有数字出现次数超过一半，那么排序之后一定是排在中间
 * 所以可以利用partition函数去找排在中间的数
 */
#include <iostream>
#include <algorithm>
#include <vector>

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
// 找到排在中间的那个数，即中位数
int getMid(vector<int> &arr) {
	int mid = arr.size() >> 1;
	int start = 0;
	int end = arr.size() - 1;
	int idx = Partition(arr, start, end);
	while (idx != mid) {
		if (idx >mid) {
			end = idx - 1;
			idx = Partition(arr, start, end);
		}
		else {
			start = idx + 1;
			idx = Partition(arr, start, end);
		}
	}
	return arr[mid];
}

int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) return 0;
	int res = getMid(numbers);
	int cnt = 0;
	for (auto i : numbers) {
		if (i == res)
			++cnt;
	}
	// 中位数不一定就出现次数超过一半，需要检验一下
	return cnt * 2 <= numbers.size() ? 0 : res;
}

int main()
{
	vector<int> numbers = {1,2,3,2,2,2,5,4,2};
	cout << MoreThanHalfNum_Solution(numbers) << endl;

	return 0;
}

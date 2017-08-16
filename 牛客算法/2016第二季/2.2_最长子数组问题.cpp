/*
 * 这是一类问题，和为某个值或者某个范围，找最长的子数组的长度
 * 以及数组元素全正数，或者有正有负的情况
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

// 未排序正数数组中累加和为给定值的最长子数组长度
// 条件：全是正数（或者0）
int getMaxLengthPositiveInteger(vector<int> arr, int k) {
	if (arr.empty() || k <= 0)
		return 0;
	int left = 0;
	int right = 0;
	int sum = arr[0];
	int len = 0;
	while (right < arr.size()) {
		if (sum == k) {
			len = max(len, right - left + 1);
			sum -= arr[left++];
		}
		else if (sum < k) {
			right++;
			if (right == arr.size()) {
				break;
			}
			sum += arr[right];
		}
		else {
			sum -= arr[left++];
		}
	}
	return len;
}

// 未排序数组（可正可负或者0）中累加和为给定值的最长子数组长度
// 变化1：求arr 所有的子数组中正数与负数个数相等的最长子数组长度
// 把数组正数全改为1，负数改为-1，然后变成计算累加和为0的最长子数组长度
// 变化2：元素只是1 或0。求arr 所有的子数组中0和1个数相等的最长子数组长度
// 把数组里的0全改-1，然后变成计算累加和为0的最长子数组长度
int getMaxLengthInteger(vector<int> arr, int k)
{
	if (arr.empty())
		return 0;
	map<int, int> map;
	map[0] = -1; // important
	int len = 0;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
		if (map.count(sum - k)) {
			len = max(i - map[sum - k], len);
		}
		if (!map.count(sum)) {
			map[sum] = i;
		}
	}
	return len;
}

// 未排序数组（可正可负或者0）中累加和小于等于给定值的最长子数组长度
int maxLengthAwesome(vector<int> arr, int k) {
	if (arr.empty())
		return 0;
	int length = arr.size();
	vector<int> sums(length);
	map<int, int> ends; // 从尾到头每个索引向后的最小累加和及其索引
	sums[length - 1] = arr[length - 1];
	ends.insert(make_pair(length - 1, length - 1));
	for (int i = length - 2; i >= 0; i--) {
		if (sums[i + 1] < 0) {
			sums[i] = arr[i] + sums[i + 1];
			ends.insert(make_pair(i, ends[i + 1]));
		}
		else {
			sums[i] = arr[i];
			ends.insert(make_pair(i, i));
		}
	}
	int end = 0;
	int sum = 0;
	int res = 0;
	for (int i = 0; i < length; i++) {
		while (end < length && sum + sums[end] <= k) {
			sum += sums[end];
			end = ends[end] + 1;
		}
		sum -= end > i ? arr[i] : 0;
		res = max(res, end - i);
		end = max(end, i + 1);
	}
	return res;
}
// 二分法找第一个大于num的元素
int getLessIndex(vector<int> arr, int num) {
	int low = 0;
	int high = arr.size() - 1;
	int mid = 0;
	int res = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] >= num) {
			res = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return res;
}

int maxLength(vector<int> arr, int k) {
	vector<int> h(arr.size() + 1);
	int sum = 0;
	h[0] = sum;
	for (int i = 0; i != arr.size(); i++) {
		sum += arr[i];
		h[i + 1] = max(sum, h[i]);//辅助数组[0,i]区间元素和的最大值
	}
	sum = 0;
	int res = 0;
	int pre = 0;
	int len = 0;
	for (int i = 0; i != arr.size(); i++) {
		sum += arr[i];
		pre = getLessIndex(h, sum - k); // 从辅助数组找第一次出现sum-k的值
		len = pre == -1 ? 0 : i - pre + 1; // pre=-1表示找不到。若找到[pre,i]的长度就是结果
		res = max(res, len); // 更新子数组长度最大值
	}
	return res;
}

int main()
{
	vector<int> arr = {2,3,1,1,1,1,1,2,3};
	cout << getMaxLengthPositiveInteger(arr, 5) << endl;

	return 0;
}

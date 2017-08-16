#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 方法1：时间复杂度O(n^2)
int findLongest(vector<int> &arr, int n) {
	if (arr.empty() || n < 1)
		return 0;
	vector<int> dp(n); // 表示[0,当前索引]区间LIS长度值
	dp[0] = 1; // 只有1个元素，LIS长度为1
	int maxLen = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1; // import
		for (int j = 0; j < i; j++) {
			// 从比当前元素小的元素中找其dp值最大的那个
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				maxLen = max(maxLen, dp[i]); // 更新最长值
			}
		}
	}
	return maxLen;
}

// 方法2：用二分查找优化到O(nlogn)
int findLongest(vector<int> &arr, int n) {
	if (arr.empty() || n < 1)
		return 0;
	vector<int> dp(n); // 表示[0,当前索引]区间LIS长度值
	vector<int> ends(n);
	ends[0] = arr[0];
	dp[0] = 1; // 只有1个元素，LIS长度为1
	int maxLen = 1;
	int l = 0;
	int r = 0;
	int m = 0;
	for (int i = 1; i < n; ++i) {
		l = 0;
		r = 
	}
}

int main()
{
	vector<int> arr = {1,5,3,9,13,7};
	cout << findLongest(arr, arr.size()) << endl;

	return 0;
}

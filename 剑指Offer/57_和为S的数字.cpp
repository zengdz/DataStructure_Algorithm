/*
 * 题目：一个递增排序的数组，在数组中找两个数使得和为sum
 * 如果有多对数字的和等于sum，输出两个数的乘积最小的
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> res;
	int start = 0;
	int end = array.size() - 1;
	// 两个索引从外向内逼近结果
	// 从排序数组的两边向中间逼近，如果找到符合的两个数，也会是乘积最小的
	while (start < end) {
		// 如果和小于sum，左边要增大
		if (array[start] + array[end] < sum)
			++start;
		// 如果和大于sum，右边要减小
		else if (array[start] + array[end] > sum)
			--end;
		else {
			res.push_back(array[start]);
			res.push_back(array[end]);
			break; // 只要找到一组就结束循环
		}
	}
	return res;
}

int main()
{
	vector<int> arr = {1,2,4,7,8,11,15};
	auto result = FindNumbersWithSum(arr, 15);
	for(auto i = result.begin(); i != result.end(); ++i)
		cout << *i << " ";
	cout << endl;

	return 0;
}

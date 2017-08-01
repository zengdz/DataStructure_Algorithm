/*
 * 设计一个高效算法，查找数组中未出现的最小正整数。
 * 给定一个整数数组A和数组的大小n，请返回数组中未出现的最小正整数。
 * 示例：[-1,2,3,4]返回1
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missLeastPositiveNum(vector<int> arr){
	if(arr.empty())
		return 0;
	// l代表遍历位置的元素在[1,l+1]上
	int l = 0;
	// r代表数组符合[1，N]时的最大值
	int r = arr.size();
	while(l < r){
		// l位置元素符合要求
		if(arr[l] == l + 1)
			++l;
		// 有3种不合要求(超出范围以及存在重复)视为无效元素
		else if(arr[l] <= l || arr[l] > r || arr[arr[l] - 1] == arr[l]){
			arr[l] = arr[--r]; // 把无效元素替换为r缩减后其位置的值
		}
		// 在范围内且不重复，交换位置把元素归位
		else
			swap(arr[l], arr[arr[l] - 1]);
	}
	return l + 1;
} 

int main()
{
	vector<int> arr = {-2,1,2,4,6,9,13};
	cout << missLeastPositiveNum(arr) << endl;

	return 0;
}

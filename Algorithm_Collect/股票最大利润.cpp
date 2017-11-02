// 求买卖股票一次能获得的最大利润。
// 输入{9，11，8，5，7，12，16，14}
// 5的时候买入，16的时候卖出，则能获得最大利润11。
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <limits.h>
#include <algorithm>

using namespace std;

// 生成随机数组 
void RandomVec(vector<int> &arr) {
	srand(unsigned(time(0)));
	for(int i = 0; i < arr.size(); ++i)
		arr[i] = rand() % 100; // 随机数的范围[0,99]
}

// 思路：以当前数卖出时，只有以前面某个最小值买入时利润最大 
int MaxRevenue(vector<int> &arr) {
	int ret = INT_MIN;
	int min_left = arr[0]; // 左边出现的最小值，初值就是第一个数 
	for(int i = 1; i < arr.size(); ++i) {
		// 当前数减左边出现的最小值就是当前数卖出能获得的最大利润
		// 比较不同数卖出所得最大利润，更新最大值 
		ret = max(ret, arr[i] - min_left);
		min_left = min(min_left, arr[i]); // 更新 
	}
	return ret;
}

// 预处理数组法：自己尝试的方法
int MaxRevenuePreArr(vector<int> &arr) {
	vector<int> Min(arr.size()); // 从左到右遍历记录遇到的最小值 
	vector<int> Max(arr.size()); // 从右到左遍历记录遇到的最大值 
	for(int i = 0; i < arr.size(); ++i) {
		if(i == 0) { // 给Min数组初值，放在循环内更整洁 
			Min[i] = arr[i]; // Min第一个值就是第一个数值 
			continue;
		}
		Min[i] = min(Min[i-1], arr[i]); // 更新最小值 
	}
	for(int i = arr.size() - 1; i >= 0; --i) {
		if(i == arr.size() - 1) {
			Min[i] = arr[i];
			continue;
		}
		Max[i] = max(Min[i+1], arr[i]);
	}
	int ret = Max[0] - Min[0]; // 初值 
	for(int i = 1; i < arr.size(); ++i) {
		// 依次比较Max和Min数组的差值，记录最大值 
		ret = max(ret, Max[i] - Min[i]);
	}
	return ret;
}

int main()
{
	vector<int> arr(13);
	bool flag = true;
	// 依靠大量循环生成大量随机数组进行测试 
	// 判断两个函数的结果是否一致，若一致说明两个函数功能一样 
	for(int i = 0; i < 300000; ++i) {
		RandomVec(arr);
		if(MaxRevenue(arr) != MaxRevenuePreArr(arr)) {
			flag = false;
			break;
		}
	}
	
	if(flag)
		cout << "666666" << endl; // 成功则666 
	else
		cout << "233333" << endl; // 失败则233 
	
	return 0;
}


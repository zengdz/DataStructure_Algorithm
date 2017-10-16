// 扩展二分查找：要求递归实现 
// 找到了返回其位置，找不到就返回左边离最近的，否则返回-1
// 比如{1,2,3,5}查找4则应该返回2，因为离4最近的是数字3索引为2

#include <iostream>

using namespace std;

// 二分查找另一种思路，传统的是锁定中间数while(lhs<=rhs)
// 新思路是锁定三个数，这种方式可以方便取得目标值的左右值
int Bin_Search(int arr[], int len, int key) {
	if(arr == nullptr)
		return -1;
	int lhs = 0;
	int rhs = len - 1;
	// 两边的边界中间夹一个元素，mid指向中间 
	while(lhs + 1 < rhs) {
		int mid = lhs + ((rhs - lhs) >> 1);
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key)
			lhs = mid; // 未判断边界，只是收缩边界，不用+1 
		else
			rhs = mid; // 未判断边界，只是收缩边界，不用-1 
	}
	// 退出循环后还剩3个数，中间不可能是目标值(会在while中return)
	// 边界值可能是目标值，要加以判断，否则就是找不到返回-1 
	if(arr[lhs] == key)
		return lhs;
	if(arr[rhs] == key)
		return rhs;
	return -1;
}

// 在原二分查找基础判断下目标值所在的范围即可
int Ex_Bin_Search(int arr[], int len, int key) {
	if(arr == nullptr)
		return -1;
	int lhs = 0;
	int rhs = len - 1;
	while(lhs + 1 < rhs) {
		int mid = lhs + ((rhs - lhs) >> 1);
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key)
			lhs = mid;
		else
			rhs = mid;
	}
	// key在[lhs,rhs)区间的结果是lhs 
	if(arr[rhs] > key && arr[lhs] <= key)
		return lhs;
	// key在[rhs,MAX_INT)区间的结果是rhs
	else if(arr[rhs] <= key)
		return rhs;
	// key在(MIN_INT,lhs)区间的结果是-1
	else
		return -1;
}

// 把扩展二分查找改成递归形式
int Core_Recur(int arr[], int lhs, int rhs, int key) {
	if(lhs + 1 < rhs) {
		int mid = lhs + ((rhs - lhs) >> 1);
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key)
			return Core_Recur(arr, mid, rhs, key);
		else
			return Core_Recur(arr, lhs, mid, key);
	}
	if(arr[rhs] > key && arr[lhs] <= key)
		return lhs;
	else if(arr[rhs] <= key)
		return rhs;
	else
		return -1;
}
// 在主体函数中调用递归函数
int Ex_Bin_Search_Recur(int arr[], int len, int key) {
	if(arr == nullptr || len < 1)
		return -1;
	int lhs = 0;
	int rhs = len - 1;
	return Core_Recur(arr, lhs, rhs, key);
}

int main() {
	int arr[] = {2,3,5,7,9,15};
	int num;
	// 从输入获取要查找的目标值
	while(cin >> num)
		cout << Ex_Bin_Search_Recur(arr, sizeof(arr)/sizeof(int), num) << endl;
	
	return 0;
}

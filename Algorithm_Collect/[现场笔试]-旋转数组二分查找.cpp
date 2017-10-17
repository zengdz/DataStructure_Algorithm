// 旋转数组糅合二分查找的复合型题目，思路细节比较复杂 
// 时间复杂度是 O(logn)找最小值 + O(logn)区间二分查找 = O(logn)

// 旋转数组衍生相关的问题：找最小值；求旋转次数
// 对于没有要求复杂度情况，排序取最小即可解决

#include <iostream>

using namespace std;

// 在某个区间上的二分查找算法(非传统版本) 
int Bin_Search(int arr[], int lhs, int rhs, int key) {
	while(lhs + 1 < rhs) {
		int mid = lhs + ((rhs -lhs) >> 1);
		if(arr[mid] > key)
			rhs = mid;
		else if(arr[mid] < key)
			lhs = mid;
		else
			return mid;
	}
	if(arr[lhs] == key)
		return lhs;
	else if(arr[rhs] == key)
		return rhs;
	else
		return -1;
}

int LinearFind(int arr[], int lhs, int rhs) {
	int res = arr[lhs];
	for(int i = lhs + 1; i <= rhs; ++i) {
		if(arr[i] < res)
			res = arr[i];
	}
	return res;
}
int FindMin_RorateArr(int arr[], int len) {
	int lhs = 0;
	int rhs = len - 1;
	
	// 如果首尾有序说明数组未旋转，首元素就是最小值 
	if(arr[lhs] < arr[rhs]) 
		return lhs;
	while(arr[lhs] >= arr[rhs]) {
		int mid = lhs + ((rhs -lhs) >> 1);
		// 缩减范围到两个数可确定最小值
		if(rhs - lhs == 1)
			return rhs;
		// 对数组中存在重复数字的情况要特殊处理
		if(arr[lhs] == arr[mid] && arr[rhs] == arr[mid])
			return LinearFind(arr, lhs, rhs);
		if(arr[lhs] <= arr[mid])
			lhs = mid;
		if(arr[rhs] >= arr[mid])
			rhs = mid;
	}
}

int Rorate_Bin_Search(int arr[], int len, int key) {
	if(arr == nullptr || len < 1)
		return -1;
	int lhs = 0;
	int rhs = len - 1;
	int boundary = FindMin_RorateArr(arr, len); // 找出旋转数组最小值的索引 
	
	// 判断是否旋转，如果未旋转，在整个数组二分查找 
	if(boundary == 0)
		 return Bin_Search(arr, lhs, rhs, key);
	
	// 如果是旋转数组，判断在哪个区间进行二分查找 
	// 注意key是和数组首元素比较，不是和最小元素比较 

	// 如果key小于首元素，说明在后半段。区间是[boundary, rhs]
	if(key < arr[lhs])
		return Bin_Search(arr, boundary, rhs, key);
	// 如果key大于首元素，key存在于前半段，首元素已排除也不可能是最小值
	// 所以查询的区间是[lhs + 1, boundary - 1]
	else if(key > arr[lhs])
		return Bin_Search(arr, lhs + 1, boundary - 1, key);
	else
		return lhs;
}

int main() {
	int test1[] = {1,2,3,4,5,6}; // 数组未旋转
	int test2[] = {4,5,6,1,2,3}; // 旋转数组
	int test3[] = {2,5,6,1,2,2}; // 存在重复数字
	int choice;
	cout << "选择测试用例-> 1未旋转；2旋转；3重复: ";
	cin >> choice;
	int num;
	while(cin >> num) {
		if(choice == 1)
			cout << Rorate_Bin_Search(test1, sizeof(test1)/sizeof(int), num) << endl;
		else if(choice == 2) 
			cout << Rorate_Bin_Search(test2, sizeof(test2)/sizeof(int), num) << endl;
		else
			cout << Rorate_Bin_Search(test3, sizeof(test3)/sizeof(int), num) << endl;
	}
	return 0;
}

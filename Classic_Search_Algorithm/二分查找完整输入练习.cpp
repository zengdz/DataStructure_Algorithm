/** 题目：根据输入数据编写完整的程序并输出对应结果
 ** 大多编程题都只要求完成函数部分，但也有一些要求写出完整程序
 ** 熟悉一些输入情况的处理，避免卡在这个环节
 ** 下面是一个测试的输入输出例子，代码加入了一些输入提示
Input:
2
5
1 2 3 4 5 
4
5
11 22 33 44 55
445

Output:
3
-1
**/
#include <stdio.h>
#include <iostream>

using namespace std;

int binary_search(int A[], int left, int right, int k)
{
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (A[mid] > k)
			right = mid - 1;
		else if (A[mid] < k)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	cout << "Input:" << endl;
	int num;
	cout << "Input number of test case: ";
	cin >> num; // 输入测试用例的个数
	int *res = new int[num]; // 保存每个测试用例的结果
	for (int idx = 0; idx < num; ++idx) {
		int length;
		cout << "Input length of array: ";
		cin >> length; // 数组的长度
		int *arr = new int[length]; // 申请指定长度的数组空间

		int t,i = 0;
		cout << "Input elements of array: ";
		// 动态数组保存输入的数组元素
		while (i < length) {
			cin >> t;
			arr[i++] = t;
		}

		// 输入待查找的数值
		int key; 
		cout << "Input the value to find: ";
		cin >> key;

		int temp = binary_search(arr, 0, length - 1, key);
		res[idx] = temp; // 把查找结果保存到动态数组

		delete [] arr;
	}

	cout << "Output:" << endl;
	// 输出所有测试用例的结果
	for (int i = 0; i < num; ++i)
		cout << res[i] << endl;

	delete [] res;

	return 0;
}

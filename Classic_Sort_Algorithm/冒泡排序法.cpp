/*
 * 冒泡排序法(默认递增排序，可以修改交换条件来改变排序方式)
 * 还有两种冒泡形式：冒小泡还是冒大泡
 * 在写代码时，画出索引的位置分布以及理解索引含义可理清思路
 */

#include <iostream>

using namespace std;

void SelfSwap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 冒泡排序-冒小泡 从后往前冒泡
void BubbleSortSmall(int *a, int n)
{
	// flag指示是否发生交换，如果没有交换说明已经有序不用处理
	bool flag = true;
	// 索引i代表循环结束位置i的元素已在有序位置
	// 冒小泡所以i从0开始，不用取到最后一个位置，i不用等于n-1
	// 因为其他有序剩下一个必然有序
	for(int i = 0; i < n-1 && flag; ++i){
		flag = false;
		// 索引j用于每轮冒泡的比较，由于是冒小泡，所以j从后面开始
		// 用于比较的索引选择的是j和j+1，所以初值即上限j+1=n-1即j=n-2
		// j的下限是i，目的就是把小泡冒泡到i位置
		for(int j = n - 2; j >= i; --j){
			// 递增排序的比较条件,若递减把比较改为小于即可
			if(a[j] > a[j+1]){
				SelfSwap(a[j], a[j+1]);
				flag = true;
			}
		}
	} 
}

// 冒泡排序-冒大泡 从前往后冒泡
void BubbleSortBig(int *a, int n)
{
	// flag指示是否发生交换，如果没有交换说明已经有序不用处理
	bool flag = true;
	// 索引i代表循环结束位置i的元素已在有序位置
	// 冒大泡所以i从n-1开始，不用取到第一个位置，i不用等于0
	// 因为其他有序剩下一个必然有序
	for (int i = n - 1; i > 0 && flag; --i) {
		flag = false;
		// 索引j用于每轮冒泡的比较，由于是冒大泡，所以j从前面开始
		// 用于比较的索引选择的是j和j+1，所以初值下限j=0
		// 上限是j+1=i，目的就是把大泡冒泡到i位置
		for (int j = 0; j + 1 <= i; ++j) {
			// 递增排序的比较条件,若递减把比较改为小于即可
			if (a[j] > a[j + 1]) {
				SelfSwap(a[j], a[j + 1]);
				flag = true;
			}
		}
	}
}

// 输出结果函数，带一个字符串参数用于输出提示信息
// 然后是被输出的数组以及数组的长度，都是输出内容所以const修饰
void PrintArrayResult(const char *s, const int arr[], const int length)
{
	cout << s << endl;
	for (int i = 0; i < length; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = {8,2,5,4,5,7,3,13,23,8,21,66,33};
	int length = sizeof(arr) / sizeof(arr[0]);

	BubbleSortSmall(arr, length);
	PrintArrayResult("Bubble sort result:", arr, length);

	return 0;
}

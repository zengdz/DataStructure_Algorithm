/* 
*  题目：有两个排序的数组A1和A2，A1有足够多余空间容纳A2，把A2所有数字插入A1，并且所有数字是排序的。
*  感觉像洗两幅排序好的扑克牌，把两副牌洗到一起，选一副牌不动，另一副牌依次比较插入
*  最后可能有剩牌无法比较，如果剩的是不动的那堆，就不动；如果是插入那堆剩了，直接全移过来。
*/
#include <stdio.h>
#include <iostream>

using namespace std;

// 假设给出的长度是实际的数据的长度，假设arr1数组长度可以再容纳arr2数组内容
// 如果给的长度是数组长度，怎么判断数组里面真实数据的个数？
// 注意：如果最后剩的是arr1，那么不用移动。剩的是arr2的话就直接移到arr1
void arr_insert(int *arr1, int length1, int* arr2, int length2) {

	if (arr1 == nullptr || arr2 == nullptr || length1 < 1 || length2 < 1)
		return;

	int new_idx = length1 + length2 - 1;
	int arr1_idx = length1 - 1;
	int arr2_idx = length2 - 1;

	// 处理两边都还有数据的情况
	while (arr1_idx >=0 && arr2_idx >= 0)
	{
		if (arr1[arr1_idx] >= arr2[arr2_idx])
			arr1[new_idx--] = arr1[arr1_idx--];
		else
			arr1[new_idx--] = arr2[arr2_idx--];
	}

	// 当arr1处理完，arr2还有数据时，直接把剩余arr2数据全移动到arr1
	// 不用判断 if (arr1_idx < 0) 来决定是arr2剩下
	// 如果数组有元素剩下，那么索引没有达到条件，就能进入while循环
	while(arr2_idx >= 0)
		arr1[new_idx--] = arr2[arr2_idx--];

	// 剩余的是arr1，位置不变所以不用处理！(如果使用了辅助数组，那么这个步骤也需要)
	//	while (arr1_idx >= 0)
	//		arr1[new_idx--] = arr1[arr1_idx--];
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
	int a1[30] = {9, 11, 13, 33, 50};
	int a2[] = {3, 5, 17, 29};

	arr_insert(a1, 5, a2, 4);

	PrintArrayResult("Insert Result:",a1, 9);

	return 0;
}

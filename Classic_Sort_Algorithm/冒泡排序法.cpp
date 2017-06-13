/*
 * 冒泡排序法
 */

#include <iostream>

using namespace std;

void SelfSwap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int *a, int n)
{
	// flag用于判断是否发生交换，如果没有交换说明已经有序不用处理
	bool flag = true;
	for(int i = 0; i < n-1 && flag; ++i){
		flag = false;
		// j是从n-2开始递减,因为是倒数第2个和倒数第1个比较,而且判断条件要取到i的值
		// 注意j的判断条件和i有关
		for(int j = n - 2; j >= i; --j){
			if(a[j] > a[j+1]){
				SelfSwap(a[j], a[j+1]);
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
	int a[] = {8,2,5,4,5,7,3,13,23,8,21,66,33};
	int length = sizeof(a) / sizeof(a[0]);

	BubbleSort(a, length);
	PrintArrayResult("Bubble sort result:", a, length);

	return 0;
}

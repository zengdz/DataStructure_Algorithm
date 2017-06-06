/*
* 基础算法--快速排序
* 归并排序的时间复杂度：最好O(nlogn),最坏O(n^2),平均O(nlogn)
* 空间复杂度：最优O(logn)，最坏O(n)
* 2017/6/6 SAIL@DG
*/
#include <stdio.h>
#include <iostream>

using namespace std;

// 或者可以使用STL的swap函数
void SelfSwap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int arr[], int low, int high)
{
	if (arr == nullptr || low > high || high < 0)
		return;
	if(low < high){
		/*---------------partition----------------*/
		// 相当于partition函数的形参赋值过程
		int pivotkey = arr[low];//选第一个元素作为枢轴量
		int i = low;
		int j = high;
		while (i < j){
			while (i < j && arr[j] >= pivotkey)
				--j;
			SelfSwap(arr[i], arr[j]); // 把小于pivotkey的元素移到左边
			while (i < j && arr[i] <= pivotkey)
				++i;
			SelfSwap(arr[i], arr[j]); // 把大于pivotkey的元素移到右边
		}
		/*---------------partition----------------*/
		int pivot = i; //把枢轴所在位置赋值给pivot 
		QuickSort(arr, low, pivot-1);
		QuickSort(arr, pivot+1, high);
	}
}

// 网上有博客写的这种方法--挖坑填数版本
// 类似于二分查找的闭区间和开区间版本，都能工作，但是闭区间版本不易出错
// 这个快速排序的边界索引处理容易出错
void QuickSort2(int s[], int l, int r)
{
	if (s == nullptr || l > r || r < 0)
		return;
	if (l < r)  {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换,中间作枢轴
        int i = l, j = r, x = s[l];  
        while (i < j) {  
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数  
                j--;    
            if(i < j)   
                s[i++] = s[j];  
            
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
                i++;
            if(i < j)
                s[j--] = s[i]; 
        }  
        s[i] = x; // 最后要填的那个坑
		QuickSort2(s, l, i - 1); // 递归调用   
		QuickSort2(s, i + 1, r);
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
	int a[] = {8,2,5,4,5,7,3,13,23,8,21,66,33,8};
	int length = sizeof(a) / sizeof(a[0]);
	PrintArrayResult("Formal unsorted array:", a, length);

	QuickSort(a, 0, length - 1);
	//QuickSort2(a, 0, length - 1);

	PrintArrayResult("Quick sort result:", a, length);

	return 0;
}

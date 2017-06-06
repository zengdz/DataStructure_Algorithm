#include <stdio.h>
#include <iostream>

using namespace std;

// 递归法：大量重复运算，使用大量栈内存，
// 运算较慢，有栈溢出风险
long Fibonacci_Recursive(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
}

// 迭代法：根据上一次运算结果进行计算
long Fibonacci_Iterative(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	int Fib_2 = 0;
	int Fib_1 = 1;
	int FibN = 0;
	for (int i = 2; i <= n; ++i) {
		FibN = Fib_1 + Fib_2; // 计算第N个斐波那契值
		// 更新变量，注意顺序
		Fib_2 = Fib_1; 
		Fib_1 = FibN;
	}
	return FibN;
}

// 动态规划法：需要额外内存空间
// 相比迭代法，更直观容易理解
long Fibonacci_DP(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	int *fib = new int[n + 1]; // 第一个元素是0，总共n+1个
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; ++i) {
		// 根据数组保存的结果计算当前斐波那契值
		fib[i] = fib[i - 2] + fib[i - 1];
	}
	return fib[n];
	delete[] fib;
}

int main()
{
	cout << Fibonacci_Iterative(39) << endl;
	cout << Fibonacci_DP(39) << endl;
	cout << Fibonacci_Recursive(39) << endl;
	
	return 0;
}

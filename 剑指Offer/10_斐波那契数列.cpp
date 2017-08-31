#include <iostream>
#include <vector>

using namespace std;

// 递归法：大量重复运算，使用大量栈内存，
// 运算较慢，有栈溢出风险
long Fibonacci_Recursive(int n) {
    if (n <= 0) // 递归的终止条件
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
}

// 动态规划法：需要额外内存空间
long Fibonacci_DP(int n) {
    // 虽然DP有每个位置的记录，不用初值判断
    // 但DP只能处理正常值输入，最好还是加上
    if (n <= 0) 
        return 0; 
    if (n == 1)
        return 1;
    vector<int> fib(n + 1); // 第一个元素是0，总共n+1个
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        // 根据数组保存的结果计算当前斐波那契值
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    return fib[n];
}

// 空间优化：使用两个变量滚动计算
long Fibonacci_SpaceCompress(int n) {
    if (n <= 0) // 空间优化没有保存每个值，需要初值判断
        return 0;
    if (n == 1)
        return 1;
    int Fib_2 = 0;
    int Fib_1 = 1;
    int FibN = 0;
    for (int i = 2; i <= n; ++i) {
        FibN = Fib_1 + Fib_2; // 计算第N个斐波那契值
        Fib_2 = Fib_1; // 更新变量，注意顺序
        Fib_1 = FibN;
    }
    return FibN;
}

int main()
{
    int n;
    cin >> n;
    cout << Fibonacci_Recursive(n) << endl;
    cout << Fibonacci_DP(n) << endl;
    cout << Fibonacci_SpaceCompress(n) << endl;

    return 0;
}

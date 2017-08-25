// https://www.nowcoder.com/questionTerminal/876e3c5fcfa5469f8376370d5de87c06
// 题目是说：给一组数，问不能用该组数凑成的最小数是哪个？
// 比如 1 2 5 7 应该输出4，因为只能凑到1,2,3 咋一看和未出现的最小正数类似
// 但是代码只通过了10%，并不适用于该算法模型
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

// 基于这样一种迭代的思想：我当前假如说可以得到最大的数为k，
// 则再来一个新的数字p，若p<=k+1，则我可以得到的最大的数为p+k，
// 若p>k+1，则会出现空挡，k+1就肯定不能再得到。

int main(){
    int miss = 0;
    int n;
    scanf("%d", &n);
    vector<long> a(n);
    for(int i = 0;i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(a[i] > miss + 1) 
            break;
        miss += a[i];
    }
    printf("%d\n",miss+1);
    
    return 0;
} 

/*
 * 题目：公鸡5块一只，母鸡3块一只，小鸡1块三只，用100元买100只鸡的所有方法
 * 要求公鸡，母鸡，小鸡都必须有
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 设公鸡为x，母鸡为y，小鸡为z，得出不定方程:
	// x+y+z=100，5x+3y+z/3=100
	cout << "方法一：O(n^2)时间复杂度" << endl;
	for (int x = 1; x < 20; ++x) {
		for (int y = 1; y < 33; ++y) {
			int z = 100 - x - y;
			if ((z % 3 == 0) && 5*x+3*y+z/3==100) {
				cout << x << " : " << y <<" : " << z << endl;
			}
		}
	}
	
	// 把不定方程2式乘以3减去1式，得到7x+4y=100
	// 解必须是整数，其中100能整除4，所以y=25-7x/4，令x=4k得：y=25-7k,z=75+3k
	// 要求每样都有，k至少为1，然后每样不能超过100，k最大为3
	cout << "方法二：O(n)时间复杂度" << endl;
	for (int k = 1; k <= 3; ++k) {
		int x = 4 * k;
		int y = 25 - 7 * k;
		int z = 75 + 3 * k;
		cout << x << " : " << y << " : " << z << endl;
	}

	return 0;
}

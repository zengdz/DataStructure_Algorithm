/*
 * 使用二分法计算浮点数的开方
 */
#include <iostream>
#include <algorithm> // abs求绝对值

using namespace std;

double BinSearch_Square(float x)
{
	// 如果是负数，返回-1
	if (x < 0)
		return -1;
	float E = 0.01; // 允许误差
	float low = 0, high = x;
	double ans = (low + high) / 2;
	while (abs(ans*ans - x) >= E) {
		if (ans*ans < x)
			low = ans;
		else
			high = ans;
		ans = (low + high) / 2;
	}
	return ans;
}

int main()
{
	cout << BinSearch_Square(-4) << endl;
	cout << BinSearch_Square(9) << endl;
	cout << BinSearch_Square(2) << endl;
	cout << BinSearch_Square(6.6) << endl;

	return 0;
}

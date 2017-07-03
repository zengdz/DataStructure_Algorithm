/*
 * 题目：数组中有个数字出现的次数超过数组长度的一半，找出该数字
 * 和数字出现次数有关，之前有道题也是求出现次数，但那是排序数组可以用二分法
 */
#include <iostream>
#include <vector>

using namespace std;

// 有可能有个数字出现多次，但没有超过一半
// 需要检验找到的数字个数是否超过一半
bool CheckMoreThanHalf(vector<int> &numbers, int num) 
{
	int times = 0;
	for (auto i : numbers) {
		if (i == num)
			++times;
	}
	return times * 2 > numbers.size() ? true : false;
}

// 记录数字出现次数，数字相同则次数加1否则减1
// 如果为0记录下一个数字及其出现次数
int MoreThanHalfNum_Solution(vector<int> &numbers) {
	if (numbers.empty())
		return 0;
	int res = numbers[0]; // 第一个数字作为初始值
	int times = 1; // 初始值为1
	// 从第二个开始依次和res比较
	for (int i = 1; i < numbers.size(); ++i) {
		if (times == 0) {
			res = numbers[i];
			times = 1;
		}
		else if (res == numbers[i])
			++times;
		else
			--times;
	}
	if (!CheckMoreThanHalf(numbers, res))
		res = 0;
	return res;
}

int main()
{
	vector<int> numbers = {1,2,3,2,2,2,5,4,2};
	cout << MoreThanHalfNum_Solution(numbers) << endl;

	return 0;
}

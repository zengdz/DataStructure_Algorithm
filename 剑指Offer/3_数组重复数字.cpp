/* 
*  题目：找出数组中重复的数字
*  在一个长度为n的数组中，所有的数字都在[0,n)范围，其中某些数字重复
*  不知道重复数字个数和重复次数，找出其中任意一个重复的数字
*  示例：长度为7的数组{2,3,1,0,2,5,3}，那么输出数字2或者3
*/
#include <stdio.h>
#include <iostream>

using namespace std;

// numbers是提供的数组，length是数组长度，duplication是找到的一个重复值
// 函数返回布尔值指示是否有重复数字
// 因为返回值已用于布尔值，找到的重复值通过形参指针或者引用传递
bool duplicate(int numbers[], int length, int* duplication)
{
	// 判断是否数组为空，长度是否小于1
	if (numbers == nullptr || length < 1) {
		return false;
	}

	for (int i = 0; i < length; ++i) {
		// 判断是否有小于0的数，以及是否落在[0,length)之间
		if (numbers[i] < 0 || numbers[i] >= length)
			return false;
	}

	// 不变式：已经处理了头i个数字
	for (int i = 0; i < length; ++i) {

		// 保证头i个数字都在对应的位置上
		while (numbers[i] != i) {
			// 如果对应位置元素还出现在其他位置，说明存在重复
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}
			// 交换两个位置的数字，把当前数字i放到i位置
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

int main()
{
	int numbers[] = {0, 5, 1, 2, 5, 4};
	int length = sizeof(numbers) / sizeof(numbers[0]);
	int duplication; // 如果找到重复值，就传递给duplication变量
	bool ret = duplicate(numbers, length, &duplication);
	if (ret) {
		cout << "Found duplication number " << duplication << endl;
	}
	else
		cout << "Not found duplication number!" << endl;

	return 0;
}

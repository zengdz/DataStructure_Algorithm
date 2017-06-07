/* 
 * 题目：把字符串中每个空格替换成"%20"，比如 We are happy! 变成 We%20are%20happy!
 * 如果从前往后进行替换，那么每次替换，后面的字符都要移动，造成重复移动
 * 如果逆向替换，先根据空格数计算好替换之后的长度，然后逆向替换，所有字符只需移动一次
 */
#include <stdio.h>
#include <iostream>

using namespace std;

// length是数组的长度，不是数组里字符的个数
void replaceSpace(char *str, int length) {
	if (str == nullptr || length <= 0)
		// 因为返回类型是void，所以return不能跟返回值
		return;
	int num_space = 0;
	int origin_length = 0;
	// origin_length用于统计字符数组中字符的个数，不包括空字符
	while (str[origin_length]) {
		++origin_length;
		if (str[origin_length] == ' ')
			++num_space; // 统计空格个数，用于计算替换后的长度
	}
	// 替换空格之后的长度，注意是空格数乘以2，不是乘以3
	int new_length = origin_length + num_space * 2; 
	if (new_length > length) // 如果替换后长度大于数组总长度则退出
		return;

	// 新旧位置的索引，由于数组从0计数，但还要包括空字符
	// 所以位置索引刚好等于新旧字符个数
	int origin_idx = origin_length;
	int new_idx = new_length;
	//while (new_idx > origin_idx && origin_idx >= 0) 
	while (new_idx != origin_idx)
	{
		// 不能写成 str[origin_idx--] == ' '
		// 只有为空格时索引才减，若写在条件判断
		// 会导致每次判断都减一，无论是否满足条件
		if (str[origin_idx] == ' ') {
			str[new_idx--] = '0';
			str[new_idx--] = '2';
			str[new_idx--] = '%';
			--origin_idx; // 不能在条件处自减
		}
		else
			str[new_idx--] = str[origin_idx--];
	}
}

int main()
{
	// 数组长度要足够长可以容纳替换空格后的字符
	char str[30] = "We are happy!";

	replaceSpace(str, 30);
	cout << str << endl;

	return 0;
}

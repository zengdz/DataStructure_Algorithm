/*
 * 单词的翻转或字符串的左旋转
 * 要求内部有序，原理都是三步反转法
 */
#include <iostream>
#include <string>

using namespace std;

// 翻转索引区间内的字符串
void ReverseStr(string& str, int from, int to) 
{
	if (from < 0 || to < 0)
		return;
	// 左边小于右边说明还有字符需要翻转
	// 但是不用判断相等，剩一个字符不用翻转
	while (from < to) {
		char temp = str[from];
		str[from++] = str[to];
		str[to--] = temp;
	}
}

// 将字符串左旋转n个字符
string LeftRotateString(string str, int n) 
{
	int length = str.size();
	if (length < 1)
		return str;
	n %= length; // 如果移动的长度超过字符串长度
	ReverseStr(str, 0, n - 1);
	ReverseStr(str, n, length - 1);
	ReverseStr(str, 0, length - 1);
	return str;
}

// 字符串语句的单词翻转
string ReverseSentence(string str) {
	int length = str.size();
	if (length < 1)
		return str;
	int idx = 0;
	// 用空格划分单词，最后一个单词是空字符结束
	// 所以i的范围要取到字符串长度以便处理空字符
	for (int i = 0; i <= length; ++i) {
		if (str[i] == ' ' || str[i] == '\0') {
			ReverseStr(str, idx, i - 1);
			idx = i + 1; // 更新单词的开头索引
		}
	}
	ReverseStr(str, 0, length - 1);
	return str;
}

int main()
{
	string str1 = "abcdefg";
	cout << str1 << endl << LeftRotateString(str1, 2) << endl;

	string str2 = "I am a student.";
	cout << str2 << endl << ReverseSentence(str2) << endl;

	return 0;
}

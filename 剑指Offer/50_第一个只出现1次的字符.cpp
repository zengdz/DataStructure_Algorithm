/*
 * 题目：在字符串中第一个只出现一次的字符或者其位置
 * 使用辅助数组构建简单哈希表，空间换时间
 */
#include <iostream>
#include <string>

using namespace std;

// 如果找不到或者输入不合法返回-1
// 本例返回的是该字符，若要返回字符位置修改第二次遍历方式
char FirstNotRepeatingChar(string str) 
{
	if (str.empty())
		return -1;
	char hash[256] = { 0 };
	for (auto ch : str)
		++hash[ch];
	// 改为索引遍历可以确定位置
	// 对字符串进行查表而不是直接从哈希表找值为1的位置
	for (auto ch : str) {
		if (hash[ch] == 1)
			return ch;
	}
	return -1;
}

int main()
{
	string str = "abaccdeff";
	cout << FirstNotRepeatingChar(str) << endl;

	return 0;
}

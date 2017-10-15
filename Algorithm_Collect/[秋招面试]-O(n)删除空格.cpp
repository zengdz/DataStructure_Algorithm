// 给定一个字符串，删除其中的空格，返回空格个数。
// 要求：时间复杂度O(n)，不能分配额外空间，只使用简单数据类型 
// 字符串还是要改成字符指针，string类型不会遇到空字符停止
 
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

// 法1：交换空格和非空格字符的思路
int delete_space(char *str) {
	if(str == nullptr)
		return -1;
	int cnt = 0; // 记录空格个数 
	for(int i = 0; str[i] != '\0'; ++i) {
		if(str[i] == ' ')
			++cnt;
	}
	// 这种使用交换的算法不能在消除空格的同时记录空格个数(至少不能简单实现)
	// 所以可以直接先遍历把空格找出来，最后复杂度O(2n)=O(n) 
	for(int i = 0; i <= strlen(str); ++i) {
		if(str[i] == ' ') { // 如果遇到空格
			int j = i;
			while(str[++j] == ' '); // 找非空格字符 
			// 如果存在空格，最后一个空格会和空字符调换
			// 所以循环时要遍历到最后一个空字符
			swap(str[i], str[j]);
		}
	}
	return cnt;
}

// 法2：用非空格字符覆盖空格，处理比较妙
// 碰到空格就移动覆盖，但是要移动后面所有字符，复杂度不是O(n)
// 当时手写代码是碰到空格就移动后面一个字符，比如"1 3"会变成"133"错误
int delete_space2(char *str) {
	if(str == nullptr)
		return -1;	
	int j = 0;
	int cnt = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] != ' ')
		// 如果i指向非空格字符，那么直接赋值，字符不变 
		// 否则j会指向最先出现的空格，i会指向最先出现的非空字符 
			str[j++] = str[i];
		else
			++cnt;
	}
	str[j] = '\0'; // 在最后加上结束字符 
	return cnt;
}

int main()
{
	string tmp;
	getline(cin, tmp);
	char *str = (char *)tmp.c_str(); // const char* -> char*
	cout << "Count space: " << delete_space(str) << endl;
	cout << str << endl;
	return 0;
}


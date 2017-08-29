// 找出输入字符串中第一个出现3次的英文字母
#include <iostream>
#include <string>
#include <ctype.h> // 判断字符类型(数字，字母，标点)
#include <map>

using namespace std;

int main()
{
	string str;
	getline(cin, str); // getline用法，不是cin.getline(str);
	map<char, int> maps;
	for (auto i : str) {
		maps[i]++; // 奇怪不能复合写成 if(isalnum(i) && maps[i]++ == 3)
		if (isalnum(i) && maps[i] == 3) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}

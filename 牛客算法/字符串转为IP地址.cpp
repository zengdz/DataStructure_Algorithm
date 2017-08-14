/*
 * 一个全是数字字符串，返回可以转化为IP串的数量。
 * 比如 101111 有7种可能的转换
 * 10.1.1.11;10.11.1.1;10.1.11.1
 * 101.1.1.1;1.0.11.11;1.0.1.111;1.0.111.1;
 */
#include <iostream>
#include <string>

using namespace std;

int process(string str, int i, int parts) {
	if (i > str.length() || parts > 4)
		return 0;
	if (i == str.length())
		return parts == 4 ? 1 : 0;
	int res = process(str, i + 1, parts + 1);
	if (str[i] == '0')
		return res;
	res += process(str, i + 2, parts + 1);
	if (i + 2 < str.length()) {
		int sum = (str[i] - '0') * 100 + (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
		if (sum < 256)
			return res + process(str, i + 3, parts + 1);
		else
			return res;
	} 
	else
		return res;
}

int convertStringToIP(string str){
	if (str.empty() || str.size() < 4 || str.size() > 12)
		return 0;
	return process(str, 0, 0);
}

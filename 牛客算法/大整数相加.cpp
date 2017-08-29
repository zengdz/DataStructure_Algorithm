/*
 * 两个用字符串存储的整数进行相加操作，对非法的输入则返回error
 * 大数操作一般转换为字符串操作。要注意两个数长度不相等时的处理
 */
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int add(string &strNum1, string &strNum2, string &strRslt)
{
	// 处理非数字字符，这种情况结果输出error
	string temp = strNum1 + strNum2;
	for (auto i : temp)
		if (isdigit(i) == 0)
			return -1;
	int len1 = strNum1.size();
	int len2 = strNum2.size();
	int carry, t, tt;
	int rslt_index = 0;
	int len = max(len1, len2);
	strRslt = string(len + 1, 0); // 两数相加最长为较长长度加1
	// 范围应该选最长的那个，如果两个加数长度不同，而且短的那个前面要补0
	string zero;
	// 把数值字符串长度补成最大值，不足则前面补0
	if (len1 < len) {
		zero.resize(len - len1, '0');
		strNum1 = zero + strNum1;
	}
	else {
		zero.resize(len - len2, '0');
		strNum2 = zero + strNum2;
	}

	// 依次从低位计算加数保存到结果的高位
	for (int i = 0; i < len; i++) {
		t = (strNum1[len - 1 - i] - '0') + (strNum2[len - 1 - i] - '0');
		if (0 == t)
			continue;
		rslt_index = i;
		tt = strRslt[rslt_index] + t; // 已有值加上新的值
		strRslt[rslt_index] = tt % 10; // 取得当前位的值
		carry = tt / 10; // 进位
		if (carry) // 如果进位不为0
			strRslt[++rslt_index] += carry; // 进位加到高位
	}
	// 把位置对调且把数字转换为字符型
	for (int i = 0; i <= rslt_index / 2; i++)
	{
		t = strRslt[i] + '0';
		strRslt[i] = strRslt[rslt_index - i] + '0';
		strRslt[rslt_index - i] = t;
	}
	return 0;
}

int main(void)
{
	string a, b, result;

	while (cin >> a >> b) {
		int res = add(a, b, result);
		if (res == -1)
			cout << "error" << endl;
		else
			cout << result << endl;
	}

	return 0;
}

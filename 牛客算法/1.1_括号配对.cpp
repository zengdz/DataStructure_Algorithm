/*
 * 题目：判断括号是否配对
 * 不使用栈的方法
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(char *str)
{
	if (str == nullptr)
		return false;
	int status = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] != '(' && str[i] != ')')
			return false;
		if (str[i] == ')' && --status < 0)
			return false;
		if (str[i] == '(')
			++status;
	}
	return status == 0;
}

// 题目进阶：
// 已知一个字符串都是由左括号(和右括号)组成
// 返回最长有效括号子串的长度(注意子串是连续的)
int maxLength(char *str)
{
	if (str == nullptr)
		return 0;
	vector<int> dp(strlen(str));
	int pre = 0;
	int res = 0;
	for (int i = 1; i < strlen(str); ++i) {
		if (str[i] == ')') {
			pre = i - dp[i - 1] - 1;
			if (pre > 0 && str[pre] == '(')
				dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
		}
		res = max(res, dp[i]);
	}
	return res;
}
int main()
{
	char *expr1 = "(())";
	char *expr2 = "(()()";
	char *expr3 = ")(";
	char *expr4 = "(()())";

	cout << expr1 << " : " << isValid(expr1) << " Length: " << maxLength(expr1) << endl;
	cout << expr2 << " : " << isValid(expr2) << " Length: " << maxLength(expr2) << endl;
	cout << expr3 << " : " << isValid(expr3) << " Length: " << maxLength(expr3) << endl;
	cout << expr4 << " : " << isValid(expr4) << " Length: " << maxLength(expr4) << endl;

	return 0;
}

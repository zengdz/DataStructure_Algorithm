/*
 * 栈的应用：判断(),{},[]是否配对
 * 比如编译器就会自动判断是否漏了一半的括号
 * 不光要考虑数量匹配还要考虑顺序，比如 )( 或者 [（]）就不是配对
 */
#include <iostream>
#include <stack>

using namespace std;

bool CheckBanlancedParenthesis(char *expr)
{
	int length = strlen(expr);
	// 如果长度不是偶数则不匹配，长度是正数所以不用判断负数情况
	if (length % 2 != 0)
		return false;
	stack<char> S;
	for (int i = 0; i < length; ++i) {
		// 如果是开括号则入栈
		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
			S.push(expr[i]);
		// 否则就是闭括号的情况
		else{
			// 如果栈是空的遇到闭括号肯定不匹配
			if (S.empty())
				return false;
			// 如果闭括号和栈顶符号不匹配也是匹配失败
			else if (expr[i] == ')' && S.top() != '(')
				return false;
			else if (expr[i] == '}' && S.top() != '{')
				return false;
			else if (expr[i] == ']' && S.top() != '[')
				return false;
			// 否则说明匹配成功，把匹配成功的开括号退栈
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

int main()
{
	char *expr1 = "[(])";
	char *expr2 = "[()]";
	char *expr3 = ")(";
	char *expr4 = "{()()}";

	cout << expr1 << " : " << CheckBanlancedParenthesis(expr1) << endl;
	cout << expr2 << " : " << CheckBanlancedParenthesis(expr2) << endl;
	cout << expr3 << " : " << CheckBanlancedParenthesis(expr3) << endl;
	cout << expr4 << " : " << CheckBanlancedParenthesis(expr4) << endl;

	return 0;
}

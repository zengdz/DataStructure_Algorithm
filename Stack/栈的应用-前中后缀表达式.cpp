/*
 * 栈的应用：Prefix，Infix，Postfix表达式计算及转换
 * 举例：中缀 a+b*c，前缀 +a*bc，后缀 abc*+
 * 步骤：以中缀转后缀为例，先把优先级高的用括号括起来 a+(b*c)
 * 然后先转内部 a+(bc*)，把括号当作整体继续转 a(bc*)+ 最后去掉括号 abc*+
 * 下面两个Gist是更加完整版参考代码
 * https://gist.github.com/mycodeschool/7702441
 * https://gist.github.com/mycodeschool/7867739
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 计算后缀表达式，不考虑分隔符，假设表达式是合理的
// 如果是前缀表达式，过程相同，只不过从后往前
int EvaluatePostfix(char *expr)
{
	if (expr == nullptr)
		exit(1);
	stack<int> S;
	int length = strlen(expr);
	for (int i = 0; i < length; ++i) {
		// 如果是操作数则入栈
		if (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/') {
			S.push(expr[i] - '0'); // 把字符转换为整数
		}
		// 否则就是操作符，从栈里取出两个操作数计算并且入栈
		else{
			int op2 = S.top(); S.pop();
			int op1 = S.top(); S.pop();
			switch (expr[i]) {
				case '+': S.push(op1 + op2); break;
				case '-': S.push(op1 - op2); break;
				case '*': S.push(op1 * op2); break;
				case '/': S.push(op1 / op2); break;
			}
		}
	}
	// 最后留在栈里唯一的数据就是计算结果
	return S.top();
}

// 返回操作符的权重，即优先级的指示
// 默认只有+-*/四种运算符，设定+-权重是1，*/为2
int getWeight(char op)
{
	int weight = 0;
	if (op == '+' || op == '-')
		weight = 1;
	else
		weight = 2;
	return weight;
}
// 中缀转换后缀表达式，使用string类型保存结果
// 只包含+-*/运算符，不包含括号
string InfixToPostfix(string expr)
{
	string res;
	stack<char> S;
	for (unsigned int i = 0; i < expr.length(); ++i) {
		if (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/')
			res += expr[i]; // string可以直接相加
		else {
			// 此处是while循环不是if，因为可能栈中有多个操作符符合条件
			// 如果栈不为空且当前操作符优先级比栈顶的要低或者相等
			// 那么把栈顶的操作符加入到结果，同时出栈
			while (!S.empty() && getWeight(expr[i]) <= getWeight(S.top())) {
				res += S.top();
				S.pop();
			}
			// 最终还要把新的操作符入栈
			S.push(expr[i]);
		}
	}
	// 如果栈不为空，说明还有操作符，直接出栈
	while (!S.empty()) {
		res += S.top();
		S.pop();
	}
	return res;
}

int main()
{
	string expr1 = "2*3+5*4-9";
	char* expr2 = "23*54*+9-";

	cout << expr1 << " : " << InfixToPostfix(expr1) << endl;
	cout << expr2 << " : " << EvaluatePostfix(expr2) << endl;

	return 0;
}

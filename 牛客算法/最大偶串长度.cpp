/* 2017/7/25 NowCoder模拟编程第一题
 如果一个字符串由两个相同字符串连接而成,就称这个字符串是偶串。
 例如"xyzxyz"和"aaaaaa"是偶串,但是"ababab"和"xyzxy"却不是。
 给出一个只包含小写字母的偶串s,你可以从字符串s的末尾删除1和或者多个字符,
 保证删除之后的字符串还是一个偶串,计算删除之后得到最长偶串长度是多少。
*/
#include <iostream>
#include <string>

using namespace std;

int fun(const string &str) {
	int length = str.size();
	// 若长度小于4则只能是2个字符，删除任意长度字符不能构成偶串
	if (length < 4)
		return 0;
	int idx = length / 2;
	while (idx > 0) {
		idx -= 1; // 刚开始写成idx -= 2;只通过50%
		// 因为idx索引已经折半了，移动1格相当于长度变化2
		string str1(str, 0, idx); // 或者使用substr函数
		string str2(str, idx, idx);
		if (str1 == str2) {
			return 2 * idx;
		}
	}
	return 0;
}

int main() 
{
	string str = "abaababaab";
	cin >> str;
	cout << fun(str) << endl;
	return 0;
}

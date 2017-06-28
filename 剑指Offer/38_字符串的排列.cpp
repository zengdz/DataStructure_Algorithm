/*
 * 字符串的全排列（C++版本支持重复字符，C版本不支持）
 * 使用C字符数组或C++字符串类型，实现方法有区别
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // use swap

using namespace std;

// 使用C++方法处理字符串，配合向量保存结果
// 注意保存结果的形参必须是引用，支持重复字符
void PermutationRecur(string str, int begin, vector<string>& res)
{
	if (begin == str.size())
		res.push_back(str);
	else {
		for (int i = begin; i != str.size(); ++i) {
			// 如果两个字母相同，则跳过
			if (i != begin && str[begin] == str[i])
				continue;
			swap(str[begin], str[i]);
			PermutationRecur(str, begin + 1, res);
			// 这个交换是不需要的，C版本里面才需要
			// str形参是传递副本，没有改变原字符串，无需再次交换
			// swap(str[begin], str[i]);
		}
	}
}
vector<string> Permutation(string str) 
{
	vector<string> vec;
	if (str.empty())
		return vec;
	PermutationRecur(str, 0, vec);
	// 如果要求按照字典序输出，则把结果排个序
	// 如果给定的字符串是有序的，可以省略排序
	//sort(vec.begin(), vec.end());
	return vec;
}

// 使用C语言字符指针计算全排列，不支持重复字符
// 不能像C++版本那样处理重复的字符
void PermutationRecurOfC(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
		cout << pStr << endl;
	else {
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
			swap(*pCh, *pBegin);
			PermutationRecurOfC(pStr, pBegin + 1);
			// 之前的交换改动了字符串位置
			// 下一次交换前，需要交换回来复位
			swap(*pCh, *pBegin);
		}
	}
}
void PermutationOfC(char* pStr)
{
	if (pStr == nullptr)
		return;
	PermutationRecurOfC(pStr, pStr);
}

int main()
{
	string str = "abc";
	vector<string> res = Permutation(str);
	cout << "Use C++ Style" << endl;
	for (auto it = res.begin(); it != res.end(); ++it) {
		cout << *it << endl;
	}

	char pStr[] = "abc"; // 需要修改字符串，只能使用字符数组
	cout << "Use C Style" << endl;
	PermutationOfC(pStr);

	return 0;
}

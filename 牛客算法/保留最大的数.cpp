/*
 * 给定一个十进制的正整数，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大
 * 比如给定整数 325 然后去除 1 个数字，得到最大的是 35
 */
#include <string>
#include <iostream>

using namespace std;

int main() {
	string s;
	int len, i;
	// 调试时可以用while循环输入case，方便测试不同情况
	cin >> s >> len;
	while (len--) {
		int slen = s.length();
		for (i = 0; i < slen - 1; i++) {
			// 循环内有i + 1所以遍历索引要小于slen - 1
			if (s[i] < s[i + 1]) {
				// 不是用迭代器遍历s.erase(iter)这样做不好处理，破坏了iter
				s.erase(s.begin() + i);
				break;
			}
		}
		// 如果是依次递减，那么最后一个就是最小的
		// 删除最后的值使得剩余值可以最大
		if (i == slen - 1)
			s.erase(s.end() - 1);
	}
	cout << s << endl;

	return 0;
}

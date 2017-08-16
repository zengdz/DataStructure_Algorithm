//1. 报数A与编号节点B之间的关系：B = (A - 1) % n + 1
//2. 删除某个节点s之后，旧编号与新编号的关系：old = (new + s - 1) % n + 1
//把 s = (m - 1) % n + 1 代入式（2）可得old = (new + m - 1) % n + 1
//即Num(n) = (Num(n - 1) + m - 1) % n + 1

// 编号从1开始，递归方式
int getResult(int n, int m) 
{
	// write code here
	if (n == 1) return 1;
	return (getResult(n - 1, m) + m - 1) % n + 1;
}
// 编号从1开始，迭代方式
int getResult(int n, int m) {
	if (n<1 || m <1)
		return -1;
	int last = 1; // 编号从1开始，如果只有1个编号，无论指定第几个，都是轮到编号1
	for (int i = 2; i <= n; ++i)
		last = (last + m - 1) % i + 1;
	return last;
}


// 编号从0开始
int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0; // 编号从0开始，如果只有1个编号，无论指定第几个，都是轮到编号0
	for (int i = 2; i <= n; ++i)
		last = (last + m) % i;
	return last;
}


#include <stdio.h>
#include <vector>
using namespace std;
struct node {
	long val, cnt;
	node(long val) :val(val), cnt(1) {}
};
int main() {
	int N, i, x, Maxi;
	while (scanf("%d", &N) != EOF) {
		vector<long> d(N);
		for (i = 0; i<N; i++) scanf("%ld", &d[i]);
		vector<node> v;
		node tmp(d[0]);
		long Max = -1;
		for (i = 1; i<N; i++)
			if (d[i] == d[i - 1]) tmp.cnt++;
			else {
				v.push_back(tmp);
				if (Max<tmp.val) {
					Max = tmp.val;
					Maxi = v.size() - 1;
				}
				tmp.val = d[i];
				tmp.cnt = 1;
			}
			v.push_back(tmp);
			if (Max<tmp.val) {
				Max = tmp.val;
				Maxi = v.size() - 1;
			}
			int n = 0;
			long cnt = 0;
			vector<node> stack;
			for (i = Maxi; n != v.size(); n++, i = (i + 1) % v.size()) {
				while (stack.size() && v[i].val>stack[stack.size() - 1].val) {
					node &m = stack[stack.size() - 1];
					cnt += m.cnt + m.cnt*(m.cnt - 1) / 2;
					stack.pop_back();
					if (stack.size()) cnt += m.cnt;
				}
				if (stack.size()) {
					if (v[i].val == stack[stack.size() - 1].val)
						stack[stack.size() - 1].cnt += v[i].cnt;
					else
						stack.push_back(v[i]);
				}
				else
					stack.push_back(v[i]);
			}
			while (stack.size()) {
				node &m = stack[stack.size() - 1];
				cnt += m.cnt*(m.cnt - 1) / 2;
				stack.pop_back();
				if (stack.size()) cnt += 2 * m.cnt;
				if (stack.size() == 1 && stack[stack.size() - 1].cnt == 1) cnt -= m.cnt;
			}
			printf("%ld\n", cnt);
	}
}
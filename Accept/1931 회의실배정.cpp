#include<stdio.h>
#include<algorithm>
int n;
struct meeting {
	int begin, end;
};
bool cmp(const struct meeting& a, const struct meeting& b) {
	if (a.end == b.end) return a.begin < b.begin;
	else return a.end < b.end;
}
struct meeting m[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &m[i].begin, &m[i].end);
	std::sort(m, m + n, cmp);
	int cnt = 1, end = m[0].end;
	for (int i = 1; i < n; i++) {
		if (end <= m[i].begin) {
			end = m[i].end;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
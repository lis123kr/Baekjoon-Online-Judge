#include<stdio.h>
#define	INF	999999999
int n, s[501], e[501];
long long c[501][501];
long long min(long long a, long long b) { return a > b ? b : a; }
long long dp(int p, int q) {
	if (p == q) return 0;
	if (p + 1 == q) {
		return s[p] * e[p] * e[q];
	}
	if (c[p][q] != INF) return c[p][q];
	for (int i = p; i <= q; i++) {
		c[p][q] = min(c[p][q],dp(p, i) + dp(i + 1, q) + s[p] * e[i] * e[q]);
	}
	return c[p][q];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 501; i++) for (int j = 0; j < 501; j++) c[i][j] = INF;
	for (int i = 1; i <= n; i++) scanf("%d %d", s + i, e + i);
	printf("%lld\n", dp(1, n));
	return 0;
}
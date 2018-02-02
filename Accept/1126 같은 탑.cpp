#include<stdio.h>
#include<string.h>
const int INF = 10000000;
int dp[51][500001];
int A[51],n;
int max(int a, int b) { return a > b ? a : b; }
int solve(int p, int s) {
	if (s > 250000) return -INF;
	if (p == n) {
		if (s == 0) return 0;
		else return -INF;
	}
	int &ret = dp[p][s];
	if (ret != -1) return ret;
	ret = solve(p + 1, s);
	ret = max(ret, solve(p + 1, s + A[p]));
	if (s > A[p]) {
		ret = max(ret, solve(p + 1, s - A[p]) + A[p]);
	}
	else {
		ret = max(ret, solve(p + 1, A[p] - s) + s);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	memset(dp, -1, sizeof(dp));
	int ans = solve(0, 0);
	printf("%d\n", ans == 0 ? -1 : ans);
	return 0;
}
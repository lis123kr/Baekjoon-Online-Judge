#include<stdio.h>
int n, dp[1001][3], r[1001], g[1001], b[1001];
int inline min(int x, int y) { return x > y ? y : x; }
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &r[i], &g[i], &b[i]);

	dp[0][0] = r[0];
	dp[0][1] = g[0];
	dp[0][2] = b[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
	}
	printf("%d\n", min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])));
	return 0;
}
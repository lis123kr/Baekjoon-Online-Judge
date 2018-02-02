#include<stdio.h>
long long MOD=1000000000LL; //define 으로하니까 틀림...
long long dp[101][10][1<<10];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 9; i++)
		dp[1][i][1 << i] = 1LL;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int s = 0; s < (1 << 10); s++) {
				if (dp[i][j][s] == 0) continue;
				if ((s&(1 << j)) == 0) continue;
				if (j + 1 <= 9) {
					dp[i + 1][j + 1][s | (1 << (j + 1))] += dp[i][j][s];
					dp[i + 1][j + 1][s | (1 << (j + 1))] %= MOD;
				}
				if (j - 1 >= 0) {
					dp[i + 1][j - 1][s | (1 << (j - 1))] += dp[i][j][s];
					dp[i + 1][j - 1][s | (1 << (j - 1))] %= MOD;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i][(1 << 10) - 1];
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
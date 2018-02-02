#include<stdio.h>
#define mod	1000000007
long long dp[101][101][101];
int main() {
	int N, L, R;
	scanf("%d %d %d", &N, &L, &R);
	dp[1][1][1] = 1LL;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			for (int r = 1; r <= R; r++) {
				dp[i][j][r] = dp[i - 1][j - 1][r] + dp[i - 1][j][r - 1] + (i - 2)*dp[i - 1][j][r];
				dp[i][j][r] %= mod;
			}
		}
	}
	printf("%lld\n", dp[N][L][R]);
	return 0;
}
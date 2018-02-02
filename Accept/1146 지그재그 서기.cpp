#include<stdio.h>
const long long mod = 1000000LL;
int t, n;
long long ncr[101][101], dp[101];
int main() {
	scanf("%d", &n);
	ncr[0][0] = 1LL;
	for (int i = 1; i <= n; i++) {
		ncr[i][0] = ncr[i][i] = 1LL;
		for (int j = 1; j <= i - 1; j++) {
			ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
			ncr[i][j] %= mod;
		}
	}
	dp[2] = dp[1] = dp[0] = 1LL;
	for (int i = 3; i <= n; i++) {
		for (int k = 1; k <= i; k += 2) {
			dp[i] += (dp[k - 1] * (dp[i - k] * ncr[i - 1][k - 1]) % mod);
			dp[i] %= mod;
		}
	}	
	if (n == 1) printf("1\n");
	else printf("%lld\n", (2LL * dp[n])%mod);
	return 0;
}
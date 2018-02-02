#include<stdio.h>
int n, dp[1111][1111][5][5];
const int mod = 1000000;
int main() {
	scanf("%d", &n);
	dp[0][0][0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int o = 0; o <= i; o++) {
			for (int L = 0; L < 2; L++) {
				for (int A = 0; A < 3; A++) {
					dp[i + 1][o + 1][L][0] += dp[i][o][L][A] %= mod;
					dp[i + 1][o + 1][L][0] %= mod;
					dp[i + 1][o][L + 1][0] += dp[i][o][L][A] %= mod;
					dp[i + 1][o][L + 1][0] %= mod;
					dp[i + 1][o][L][A + 1] += dp[i][o][L][A] %= mod;
					dp[i + 1][o][L][A + 1] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int o = 0; o <= n; o++) {
		for (int L = 0; L < 2; L++) {
			for (int A = 0; A < 3; A++) {
				ans += dp[n][o][L][A] % mod;
			}
		}
	}
	printf("%d\n", n==0 ? 0 : ans % mod);
	return 0;
}
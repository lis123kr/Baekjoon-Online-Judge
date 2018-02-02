#include<stdio.h>
int t, n, ncr[22][22];
int main() {
	ncr[0][0] = 1;
	for (int i = 1; i <= 20; i++) {
		ncr[i][0] = ncr[i][i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
		}
	}
	scanf("%d", &t);
	long long dp[22] = { 0 };
	dp[2]=dp[1]=dp[0]=1;
	for (int i = 3; i <= 20; i++) {
		for (int k = 1; k <= i; k+=2) {
			dp[i] += dp[k - 1] * dp[i - k] * ncr[i-1][k-1];
		}
	}
	while (t--) {		
		scanf("%d", &n);
		if (n == 1) printf("1\n");
		else printf("%lld\n", 2*dp[n]);
	}
	return 0;
}
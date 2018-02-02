#include<stdio.h>
typedef long long LL;
int n;
LL dp[111];
LL max(LL  a,LL b) { return a > b ? a : b; }
int main() {
	scanf("%d", &n);
	dp[1] = 1LL;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int k = 3; i - k > 0; k++) {
			dp[i] = max(dp[i], dp[i - k] * (LL)(k - 1));
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}
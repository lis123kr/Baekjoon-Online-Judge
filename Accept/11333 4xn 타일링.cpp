#include<stdio.h>
#define mod 1000000007
int t, n;
long long dp[10001] = { 1,0,0,3 };
int main() {
	scanf("%d", &t);
	for (int i = 6; i <= 10000; i += 3) {
		dp[i] = (3 * dp[i - 3]);
		for (int j = 6,p=0; i - j >= 0; j += 3, p+=2) {
			dp[i] += (4+p) *dp[i - j];
		}
		dp[i] %= mod;
	}
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}
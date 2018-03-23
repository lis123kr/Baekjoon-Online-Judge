#include<stdio.h>
#include<string.h>
#define MOD	1000000000000000
long long n, m, k;
long long dp[201][101];
long long ncr(long long a, long long b) {
	if (a == b || b == 0) return 1LL;
	if (dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = (ncr(a - 1, b - 1) % MOD + ncr(a - 1, b) % MOD) %MOD;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%lld %lld %lld", &n, &m, &k);
	long long t;
	if (ncr(n + m, m) < k) {
		printf("-1\n");
		return 0;
	}
	while (n > 0 && m > 0) {
		t = ncr(n-1+m, m);
		if (t >= k) {
			printf("a");
			n -= 1;
		}
		else{
			printf("z");
			k -= t;
			m -= 1;
		}
	}
	for (int i = 0; i < n; i++)
		printf("a");
	for (int i = 0; i < m; i++)
		printf("z");
	printf("\n");
	return 0;
}
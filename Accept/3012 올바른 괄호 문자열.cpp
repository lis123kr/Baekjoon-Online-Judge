#include<stdio.h>
#define mod	100000LL
char c[222];
long long dp[222][222];
char open[5] = "({[", close[5] = ")}]";
int over = 0;
long long solve(int p, int q) {
	if (p > q) return 1;
	if (dp[p][q] != -1) return dp[p][q];
	dp[p][q] = 0;
	for (int i = p + 1; i <= q; i+=2) {
		for (int j = 0; j < 3; j++) {
			if (c[p] == '?' || c[p] == open[j]) {
				if (c[i] == '?' || c[i] == close[j]) {
					dp[p][q] += solve(p + 1, i - 1) * solve(i + 1, q);
					if (dp[p][q] > mod) over = 1;
					dp[p][q] %= mod;
				}
			}
		}		
	}
	return dp[p][q];
}
int main() {
	int n;
	scanf("%d", &n);
	scanf(" %s", c);
	for (int i = 0; i <= 200; i++)for (int j = 0; j <= 200; j++)dp[i][j] = -1;
	long long ans = solve(0, n - 1) % mod;
	if (over == 1 && n%2==0)
		printf("%05lld\n", ans);
	else
		printf("%lld\n", ans);
	return 0;
}
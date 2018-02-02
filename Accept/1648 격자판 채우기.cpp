#include<stdio.h>
#include<string.h>
const int mod = 9901;
int n, m, dp[14 * 14][1 << 14];
int solve(int p, int s) {
	if (p == n*m && s == 0) return 1;
	if (p >= n*m) return 0;
	if (dp[p][s] >= 0)
		return dp[p][s];
	int ans = 0;
	if (s & 1) {
		ans = solve(p + 1, s >> 1);
	}
	else {
		ans = solve(p + 1, (s >> 1) | (1 << (m - 1)));
		if ((p%m != m-1) && (s & 2) == 0) {
			ans += solve(p + 2, (s >> 2));
		}
	}
	return dp[p][s] = ans%mod;
}
int main() {
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));	
	printf("%d\n", solve(0, 0)%mod);
	return 0;
}
#include<cstdio>
long long dp[51][51][51][51];
const long long mod = 1000000007LL;
int main() {
	int n, a, b, c;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	dp[0][0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int p1 = 0; p1 <= a; p1++) {
			for (int p2 = 0; p2 <= b; p2++) {
				for (int p3 = 0; p3 <= c; p3++) {
					if (p1 != 0) {
						dp[i][p1][p2][p3] += dp[i - 1][p1 - 1][p2][p3];
						if(p2 != 0)
							dp[i][p1][p2][p3] += dp[i - 1][p1 - 1][p2-1][p3];
						if(p3!=0)
							dp[i][p1][p2][p3] += dp[i - 1][p1 - 1][p2][p3-1];
						if(p2!=0 && p3!=0)
							dp[i][p1][p2][p3] += dp[i - 1][p1 - 1][p2-1][p3 - 1];
					}
					if (p2 != 0) {
						dp[i][p1][p2][p3] += dp[i - 1][p1][p2 - 1][p3];
						if(p3!=0)
							dp[i][p1][p2][p3] += dp[i - 1][p1][p2 - 1][p3-1];
					}
					if(p3!=0)
						dp[i][p1][p2][p3] += dp[i - 1][p1][p2][p3 - 1];
					dp[i][p1][p2][p3] %= mod;
				}
			}
		}		
	}
	printf("%lld\n", dp[n][a][b][c]);
	return 0;
}
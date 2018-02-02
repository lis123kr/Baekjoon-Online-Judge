#include<stdio.h>
const int INF = 99999999;
int n, m, k, path[301][301],a,b,c, dp[301][301];
int max(int a, int b) { return a > b ? a : b; }
int solve(int p, int q) {
	if (q > m) return -INF;
	if (p == n) return 0;
	if (dp[p][q] != -INF)
		return dp[p][q];
	for (int i = p + 1; i <= n; i++) {
		if (path[p][i] > 0) {
			dp[p][q] = max(dp[p][q], solve(i, q + 1)+path[p][i]);
		}
	}
	return dp[p][q];
}
int main() {
	for (int i = 0; i <= 300; i++)
		for (int j = 0; j <= 300; j++)
			dp[i][j] = -INF;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		path[a][b] = max(path[a][b], c);
	}
	printf("%d\n", solve(1, 1));
	return 0;
}
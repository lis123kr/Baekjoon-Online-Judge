#include<stdio.h>
const int INF = 999999999;
int n, arr[5001], dp[5001][5001];
int min(int a, int b) { return a > b ? b : a; }
int solve(int p, int q) {
	if (p >= q)
		return 0;
	if (dp[p][q] != INF)
		return dp[p][q];
	if (arr[p] == arr[q]) {
		dp[p][q] = solve(p + 1, q - 1);
	}
	return dp[p][q] = min(dp[p][q], min(solve(p + 1, q), solve(p, q - 1)) + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i <= 5000; i++)
		for (int j = 0; j <= 5000; j++)
			dp[i][j] = INF;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf("%d\n", solve(0, n - 1));
	return 0;
}
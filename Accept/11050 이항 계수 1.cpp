#include<stdio.h>
int dp[20][20];
int ncr(int n, int k) {
	if (n == k || k == 0 || n==1) return 1;
	if (dp[n][k] != 0) return dp[n][k];
	return dp[n][k] = ncr(n - 1, k - 1) + ncr(n - 1, k);
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", ncr(n, k));
	return 0;
}
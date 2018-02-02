#include<stdio.h>
#include<string.h>
char str[501];
int dp[501][501];
int max(int a, int b) { return a > b ? a : b; }
int solve(int p, int q) {
	if (p >= q)
		return 0;
	if (dp[p][q] != -1)
		return dp[p][q];
	int h = 0;
	h = max(solve(p + 1, q), solve(p, q - 1));
	if (str[p] == 'a') {
		for (int i = p + 1; i <= q; i++) {
			if (str[i] == 't') {
				h = max(h, solve(p + 1, i - 1) + solve(i + 1, q) + 2);
			}
		}
	}
	else if (str[p] == 'g') {
		for (int i = p + 1; i <= q; i++) {
			if (str[i] == 'c') {
				h = max(h, solve(p + 1, i - 1) + solve(i + 1, q) + 2);
			}
		}
	}
	return dp[p][q] = h;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s", str);
	printf("%d\n", solve(0, strlen(str) - 1));
	return 0;
}
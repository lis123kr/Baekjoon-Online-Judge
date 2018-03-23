#include<stdio.h>
#include<string.h>
struct STAT {
	int STR, INT, PT;
}stats[101];
int inline max(int a, int b) { return a > b ? a : b; }
int n, dp[1001][1001];
int solve(int STR, int INT) {
	int h = 0, p = 0;
	if (dp[STR][INT] != -1)
		return dp[STR][INT];
	for (int i = 0; i < n; i++) {
		if (stats[i].STR <= STR || stats[i].INT <= INT) {
			h++;
			p += stats[i].PT;
		}
	}
	p = p - (STR - 1 + INT - 1);
	for (int i = 0; i < n; i++) {
		if (stats[i].STR > STR && stats[i].INT > INT) {
			if (STR + p >= stats[i].STR) {
				h = max(h, solve(stats[i].STR, INT));
			}
			if (INT + p >= stats[i].INT) {
				h = max(h, solve(STR, stats[i].INT));
			}
		}
	}
	return dp[STR][INT] = h;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &stats[i].STR,&stats[i].INT,&stats[i].PT);
	}
	printf("%d\n", solve(1, 1));
	return 0;
}
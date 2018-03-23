#include<stdio.h>
#include<string.h>
int n, left[20], m[12][12], cache[20][1<<20];
int inline max(int a, int b) { return a > b ? a : b; }
int index(int y, int x) {
	return n - (y - 1) + x - 1;
}
int solve(int p,int s) {
	if (p == 2 * n) 
		return 0;
	int y = p <= n ? 1 : p - n + 1, xx = p > n ? n : p, h = 0;
	if (cache[p][s] != -1)
		return cache[p][s];
	for (int i = y, j = xx; i <= n && j>=1; j--,i++) {
		int idx = index(i, j);
		if (m[i][j] == 1 && left[idx] == 0) {
			m[i][j] = 0;
			left[idx] = 1;
			h = max(h, solve(p + 1, s | (1<<idx)) + 1);
			left[idx] = 0;
			m[i][j] = 1;
		}
	}
	h = max(h, solve(p + 1, s));
	return cache[p][s] = h;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &m[i][j]);
	int ans = 0;
	printf("%d\n", solve(1, 0));
	return 0;
}
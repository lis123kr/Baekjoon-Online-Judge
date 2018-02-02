#include<stdio.h>
bool c[101][101], d[101][101];
bool solve(int n, int m) {
	if (c[n][m]) return d[n][m];
	c[n][m] = true;
	d[n][m] = false;
	for (int i = 1; i < m; i++) {
		if (!solve(i, m - i)) {
			d[n][m] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!solve(i, n - i)) {
			d[n][m] = true;
		}
	}
	return d[n][m];
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	c[1][1] = true;
	d[1][1] = false;
	printf("%c\n", solve(n, m) ? 'A' : 'B');
	return 0;
}
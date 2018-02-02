#include<stdio.h>
int main() {
	int n, s, m, v[101];
	int chk[101][1001] = { 0 };
	scanf("%d %d %d", &n, &s, &m);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	chk[0][s] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (chk[i][j] == 1 && j - v[i] >= 0) chk[i + 1][j - v[i]] = 1;
			if (chk[i][j] == 1 && j + v[i] <= m) chk[i + 1][j + v[i]] = 1;
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (chk[n][i] == 1 && ans < i) ans = i;
	}
	printf("%d\n", ans);
	return 0;
}
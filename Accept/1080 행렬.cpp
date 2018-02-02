#include<stdio.h>
int n, m;
int a[51][51], b[51][51];
void conv(int y,int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			a[i][j] = a[i][j] == 0 ? 1 : 0;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &b[i][j]);
	int cnt = 0;
	for (int i = 0; i <= n-3; i++) {
		for (int j = 0; j <= m-3; j++) {
			if (a[i][j] != b[i][j]) {
				conv(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
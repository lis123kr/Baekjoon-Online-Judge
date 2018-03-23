#include<stdio.h>
int n, m, b[51][51];
char board[51][51];
int inline min(int a, int b) { return a > b ? b : a; }
char change(char p) {
	if (p == 'W') return 'B';
	else return 'W';
}
int solve(int y, int x) {
	char bw = board[y][x];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if(i!=0)
			bw = change(bw);
		for (int j = 0; j < 8; j++) {
			if (board[i + y][j + x] != bw)
				cnt++;
			bw = change(bw);
		}
	}
	return cnt < 32 ? cnt : 64 - cnt;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = board[i][j] == 'B' ? 0 : 1;
	int ans = 1e9;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			ans = min(ans, solve(i, j));
		}
	}
	printf("%d\n", ans);
	return 0;
}
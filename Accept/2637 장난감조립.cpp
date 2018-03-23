#include<stdio.h>
int n, m, cnt[102][101];
bool chk[101];
void solve(int num, int mul) {
	for (int i = 1; i < n; i++) {
		if (i == num) continue;
		if (cnt[num][i] > 0) {
			cnt[n + 1][i] += cnt[num][i] * mul;
			solve(i, cnt[num][i]*mul);
		}
	}
}
int main() {
	int x, y, k;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &k);
		chk[x] = true;
		cnt[x][y] = k;
	}
	solve(n, 1);
	for (int i = 1; i < n; i++) {
		if (!chk[i]) {
			printf("%d %d\n", i, cnt[n + 1][i]);
		}
	}
	return 0;
}
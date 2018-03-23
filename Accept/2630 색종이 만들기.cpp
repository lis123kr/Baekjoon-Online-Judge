#include<stdio.h>
int n, arr[200][200], cnt[2];
int solve(int y, int x, int s) {
	if (s == 1) {
		return arr[y][x];
	}
	int a1 = solve(y, x, s / 2);
	int a2 = solve(y, x + s / 2, s / 2);
	int a3 = solve(y + s / 2, x, s / 2);
	int a4 = solve(y + s / 2, x + s / 2, s / 2);
	if (a1 != -1 && a1 == a2 && a2 == a3 && a3 == a4 && a4 == a1)
		return a1;
	else {
		cnt[a1]++; cnt[a2]++; cnt[a3]++; cnt[a4]++;
		return -1;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	solve(1, 1, n);
	printf("%d\n%d\n", cnt[0], cnt[1]);
	return 0;
}
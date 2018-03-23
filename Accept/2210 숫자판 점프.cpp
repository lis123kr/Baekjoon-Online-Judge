#include<stdio.h>
int arr[5][5], chk[1000000], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int solve(int y, int x, int cnt, int val) {
	if (cnt == 6) {
		if (!chk[val]) {
			return chk[val] = 1;
		}
		else {
			return 0;
		}
	}
	int h = 0;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y, nx = dx[i] + x;
		if (ny >= 0 && ny <= 4 && nx >= 0 && nx <= 4) {
			h += solve(ny, nx, cnt + 1, val * 10 + arr[ny][nx]);
		}
	}
	return h;
}
int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans += solve(i, j, 1, arr[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include<stdio.h>
#include<string.h>
int r, c, dy[3] = { -1,0,1 }, visited[10000][500];
char map[10000][501];
int solve(int y, int x) {
	if (x == c - 1)
		return 1;
	visited[y][x] = 1;
	int h = 0;
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i], nx = x+1;
		if (0 <= ny && ny < r) {
			if (map[ny][nx] != 'x' && !visited[ny][nx]) {
				h = solve(ny, nx);
				if (h == 1)
					return h;
			}
		}
	}
	return h;
}
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", map[i]);
	int ans = 0;
	for (int i = 0; i < r; i++) {
		if(map[i][1] != 'x')
			ans += solve(i, 1);
	}
	printf("%d\n", ans);
	return 0;
}
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
char G[101][101];
bool visited[101][101];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 }, n;
void dfs(int y,int x, bool f) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
			if (!visited[ny][nx]) {
				if (f) {
					if (G[y][x] == G[ny][nx] || (G[y][x] == 'R' && G[ny][nx] == 'G') || (G[y][x] == 'G' && G[ny][nx] == 'R')) {
						dfs(ny, nx, f);
					}
				}
				else {
					if (G[y][x] == G[ny][nx]) {
						dfs(ny, nx, f);
					}
				}
			}
		}
	}
}
pair<int,int> dfsall() {
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, true);
				b++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, false);
				a++;
			}
		}
	}
	return make_pair(a, b);
}
int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &G[i][j]);
	pair<int, int> ans = dfsall();
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}
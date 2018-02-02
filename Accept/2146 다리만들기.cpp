#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct land {
	int y, x, c;
	land(int y, int x, int c) :y(y), x(x), c(c) {}
};
int n, arr[101][101], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[101][101];
void bfs(int y, int x, int c) {
	queue< pair<int, int> >q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	arr[y][x] = c;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = t.first + dy[i], nx = t.second + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				if (!visited[ny][nx] && arr[ny][nx] > 0) {
					visited[ny][nx] = true;
					arr[ny][nx] = c;
					q.push(make_pair(ny, nx));
				}
			}			
		}
	}
}
int bfs2(int y, int x, int c) {
	queue< land > q;
	q.push(land(y, x, 0));
	bool chk[101][101] = { 0 };
	chk[y][x] = true;
	int ans = 1e9;
	while (!q.empty()) {
		land a = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = a.y + dy[i], nx = a.x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				if (!chk[ny][nx]) {
					chk[ny][nx] = true;
					if (arr[ny][nx] == c) {
						q.push(land(ny, nx, a.c));
					}
					else if (arr[ny][nx] == 0) {
						q.push(land(ny, nx, a.c + 1));
					}
					else {
						ans = min(ans, a.c);
					}
				}
			}
		}
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && arr[i][j] > 0)
				bfs(i, j, ++c);
	memset(visited, 0, sizeof(visited));
	int ans = 1e9;
	for (int i = 1; i <= c; i++) {
		for (int p = 0; p < n; p++) {
			for (int q = 0; q < n; q++) {
				if (!visited[p][q] && arr[p][q] == i) {
					ans = min(ans, bfs2(p, q, i));
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
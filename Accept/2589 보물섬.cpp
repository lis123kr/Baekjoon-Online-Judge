#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Land {
	int y, x;
	int dist;
	Land() {}
	Land(int y, int x, int dist) :y(y), x(x), dist(dist) {}
};
int n, m, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool visited[55][55];
char A[55][55];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &A[i][j]);
	queue<Land> q;
	int ans=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			if (!visited[i][j] && A[i][j] == 'L') {
				q.push(Land(i, j, 0));
				visited[i][j] = true;
				while (!q.empty()) {
					Land L = q.front();
					q.pop();
					int cy = L.y, cx = L.x;
					if (ans < L.dist) {
						ans = L.dist;
					}
					for (int p = 0; p < 4; p++) {
						int ny = cy + dy[p], nx = cx + dx[p];
						if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n) && !visited[ny][nx] && A[ny][nx] == 'L') {
							visited[ny][nx] = true;	// push할때 체크안하면 메모리초과
							q.push(Land(ny, nx, L.dist + 1));
						}
					}
				}
			}
		}
	}	
	printf("%d\n", ans);
	return 0;
}
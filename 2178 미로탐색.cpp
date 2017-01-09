#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define INF	1e9
using namespace std;

int n, m;
vector< vector<int> > g;
bool visited[100][100];
//int DFS(int y,int x) {
//	if (y < 0 || x < 0 || x == m || y == n) return INF;
//	if (g[y][x] == 0) return INF;		
//	if (y == n - 1 && x == m - 1) return 1;
//	int h = INF;
//	visited[y][x] = true;
//	if (!visited[y + 1][x])
//		h = min(h, DFS(y + 1, x));
//	if (!visited[y][x+1])
//		h = min(h, DFS(y, x + 1));
//	if (!visited[y - 1][x])
//		h = min(h, DFS(y - 1, x));
//	if (!visited[y][x-1])
//		h = min(h, DFS(y, x - 1));		
//	return h+1;
//}

void BFS(int y, int x) {
	queue< pair< pair<int,int> , int> > q;
	q.push(make_pair(make_pair(y, x), 0));
	visited[y][x] = true;
	while (!q.empty()) {
		int ny = q.front().first.first, nx = q.front().first.second;
		int distance = q.front().second;
		if (ny == n - 1 && nx == m - 1) { printf("%d", distance+1); break; }
		
		q.pop();
		if (ny + 1 != n && g[ny + 1][nx] != 0 && !visited[ny + 1][nx]) {
			q.push(make_pair(make_pair(ny + 1, nx), distance+1));
			visited[ny + 1][nx] = true;
		}
		if (nx + 1 != m && g[ny][nx+1] != 0 && !visited[ny][nx+1]) {
			q.push(make_pair(make_pair(ny, nx+1), distance + 1));
			visited[ny][nx+1] = true;
		}
		if (ny - 1 != -1 && g[ny - 1][nx] != 0 && !visited[ny - 1][nx]) {
			q.push(make_pair(make_pair(ny - 1, nx), distance + 1));
			visited[ny - 1][nx] = true;
		}
		if (nx - 1 != -1 && g[ny][nx - 1] != 0 && !visited[ny][nx - 1]) {
			q.push(make_pair(make_pair(ny, nx-1), distance + 1));
			visited[ny][nx - 1] = true;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d",&n,&m);
	char buffer[101];
	g = vector< vector<int> >(n);
	for (int i = 0; i < n; i++) {
		scanf("%s", buffer);
		g[i] = vector<int>(m);
		for (int j = 0; j < m; j++) {
			g[i][j] = buffer[j] - '0';
		}
	}
	BFS(0, 0);
	return 0;
}
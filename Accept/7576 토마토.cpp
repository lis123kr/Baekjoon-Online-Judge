#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct Node {
	int y, x, w;
	Node(int y, int x, int w) : y(y), x(x), w(w) {};
};
const int INF = 99999999;
int n, m, dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int arr[1001][1001], T[1001][1001];
bool visited[1001][1001], all=true;
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			T[i][j] = arr[i][j] != -1 ? INF : 0;
			if (arr[i][j] == 0)
				all = false;
		}
	}
	if (all) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				queue<Node> q;
				q.push(Node(i, j, 0));
				visited[i][j] = true;
				T[i][j] = 0;
				while (!q.empty()) {
					Node N = q.front();
					q.pop();
					for (int d = 0; d < 4; d++) {
						int nx = N.x + dx[d], ny = N.y + dy[d];
						if (nx >= 0 && ny >= 0 && ny < n && nx < m) {
							if (arr[ny][nx] == 0 && !visited[ny][nx]) {
								if (T[ny][nx] > N.w) {
									T[ny][nx] = N.w + 1;
									visited[ny][nx] = true;
									q.push(Node(ny, nx, N.w + 1));
								}
							}
						}
					}
				}
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans < T[i][j])
				ans = T[i][j];
		}
	}
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}
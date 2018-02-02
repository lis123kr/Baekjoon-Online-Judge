#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
struct Node {
	int y, x, w;
	Node(int y, int x, int w) : y(y), x(x), w(w) {};
};
int n, arr[111][111], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[111][111];
int main() {
	cin >> n;
	int min = 9999, max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (min > arr[i][j])
				min = arr[i][j];
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	int ans = 0;
	for (int d = min; d <= max; d++) {
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] >= d && !visited[i][j]) {
					cnt += 1;
					visited[i][j] = true;
					queue<Node>q;
					q.push(Node(i, j, arr[i][j]));
					while (!q.empty()) {
						Node N = q.front();
						q.pop();
						for (int p = 0; p < 4; p++) {
							int ny = N.y + dy[p], nx = N.x + dx[p];
							if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
								if (arr[ny][nx] >= d && !visited[ny][nx]) {
									q.push(Node(ny, nx, arr[ny][nx]));
									visited[ny][nx] = true;
								}
							}
						}
					}
				}
			}
		}
		if (cnt > ans)
			ans = cnt;
	}
	printf("%d\n", ans);
	return 0;
}
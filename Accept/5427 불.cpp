#include<stdio.h>
#include<string.h>
#include<queue>
struct Node {
	int y, x, isfire, time;
	Node(int y, int x, int isfire, int time) :y(y), x(x), isfire(isfire), time(time) {};
};
int t,w,h,dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char building[1001][1001] = { 0 };
bool visited[1001][1001] = { 0 };
int main() {
	scanf("%d", &t);
	while (t--) {
		int ans = 0, y,x;
		memset(visited, 0, sizeof(visited));
		std::queue< Node > q;
		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %c", &building[i][j]);
				if (building[i][j] == '*') {
					q.push(Node(i, j, 1, 1));
					visited[i][j] = true;
				}
				if (building[i][j] == '@')
					y = i, x = j;
			}
		}
		q.push(Node(y, x, 0, 1));

		while (!q.empty()) {
			Node tmp = q.front(); q.pop();
			visited[tmp.y][tmp.x] = true;
			if (tmp.isfire == 0 && (tmp.y == 0 || tmp.y == h - 1 || tmp.x == 0 || tmp.x == w - 1)) {
				ans = tmp.time;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = tmp.x + dx[i], ny = tmp.y + dy[i];
				if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
					if (!visited[ny][nx] && building[ny][nx] != '#') {
						visited[ny][nx] = true;
						q.push(Node(ny, nx, tmp.isfire, tmp.time + 1));
					}
				}
			}
		}
		if (ans == 0)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
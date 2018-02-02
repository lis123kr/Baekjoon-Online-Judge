#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
// 벽뚫고 빠르게 간 길보다
// 돌아서 도착했을때
// 그다음 길이 막혔다면 빠르게 간 길은 불가능해서
// 길을 돌아가야하므로...
// 예제
// 6 4
// 0000
// 1110
// 0000
// 1111
// 0111
// 0000
struct node {
	int y, x, cnt, c;
	node(int y, int x, int cnt, int c) :y(y), x(x), cnt(cnt), c(c) { };
};
int n, m, arr[1001][1001], visited[1001][1001];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
int main() {
	memset(visited, 1, sizeof(visited));
	scanf("%d %d", &n, &m); 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	queue<node> q;
	q.push(node(1, 1, 1, 0));
	visited[1][1] = 1;
	int ans = 123456789, ny,nx;
	while (!q.empty()) {
		node nq = q.front();
		q.pop();
		if (nq.y == n && nq.x == m) {
			ans = ans > nq.cnt ? nq.cnt : ans;
			if (nq.c == 1)
				ans -= 10000000;
			break;
		}
		for (int i = 0; i < 4; i++) {
			ny = nq.y + dy[i], nx = nq.x + dx[i];
			if (ny > 0 && nx > 0 && ny <= n && nx <= m) {
				if (visited[ny][nx] >= nq.cnt + 1) {
					if (arr[ny][nx] == 0) {
						visited[ny][nx] = nq.cnt + 1;
						q.push(node(ny, nx, nq.cnt + 1, nq.c));
					}
					else if (nq.c == 0) {
						visited[ny][nx] = nq.cnt + 10000001;			
						q.push(node(ny, nx, nq.cnt + 10000001, 1));		
					}													
				}														
			}
		}
	}
	printf("%d\n", ans == 123456789 ? -1 : ans);
	return 0;
}
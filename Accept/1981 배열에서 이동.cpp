#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int y, x;
	Node(int y, int x) :y(y), x(x){}
};
int n, A[111][111];
int dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 };
bool visited[111][111];
bool chk(int ms, int me) {
	if (ms > A[1][1] || me < A[1][1])
		return false;
	memset(visited, 0, sizeof(visited));
	queue<Node>q;
	q.push(Node(1, 1));
	visited[1][1] = true;
	while (!q.empty()) {
		Node tmp = q.front(); q.pop();
		if (tmp.y == n && tmp.x == n)
			return true;
		for (int i = 0; i < 4; i++) {
			int ny = tmp.y + dy[i], nx = tmp.x + dx[i];
			if (ny > 0 && nx > 0 && ny <= n && nx <= n && !visited[ny][nx]) {
				if (ms <= A[ny][nx] && A[ny][nx] <= me) {
					visited[ny][nx] = true;
					q.push(Node(ny, nx));
				}
			}
		}
	}
	return false;
}
bool solve(int c) {
	for (int i = 0; i + c <= 200; i++) {
		if (chk(i, i + c)) {
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &A[i][j]);
	int left = 0, right = 200;
	int ans= 200;
	while (left <= right) {		
		int mid = (left + right) / 2;
		if (solve(mid)) {
			right = mid - 1;
			ans = min(ans,mid);
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
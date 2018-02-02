#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
struct Node {
	int x, y, z, d;
	Node(int x, int y, int z, int d) :x(x), y(y), z(z), d(d){}
};
bool visited[101][101][101];
int n, m, h, arr[101][101][101];
int dx[6] = { -1,1,0,0,0,0 }, dy[6] = { 0,0,-1,1,0,0 }, dz[6] = { 0,0,0,0,-1,1 };
int main() {
	memset(arr, -1, sizeof(arr));
	scanf("%d %d %d", &m, &n, &h);
	queue< Node > q;
	for (int z = 0; z < h; z++) { // h
		for (int y = 0; y < n; y++) { // n
			for (int x = 0; x < m; x++) { // m			
				scanf("%d", &arr[z][y][x]);
				if (arr[z][y][x] == 1) {
					visited[z][y][x] = true;
					q.push(Node(x, y, z, 0));
				}
			}
		}
	}
	int ans = 0;
	while (!q.empty()) {
		Node nd = q.front(); q.pop();
		if (ans < nd.d)
			ans = nd.d;
		for (int i = 0; i < 6; i++) {
			int nx = nd.x + dx[i], ny = nd.y + dy[i], nz = nd.z + dz[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < m && ny < n && nz < h) {
				if (!visited[nz][ny][nx] && arr[nz][ny][nx] == 0) {
					q.push(Node(nx, ny, nz, nd.d + 1));
					visited[nz][ny][nx] = true;
				}
			}
		}
	}
	
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (arr[z][y][x] == 0 && !visited[z][y][x]) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
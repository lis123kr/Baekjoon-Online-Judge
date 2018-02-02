#include<stdio.h>
#include<string.h>
bool visited[55][55];
int t, G[55][55],m,n;
void dfs(int p, int q) {
	if (p < 0 || q < 0 || p >= n || q >= m) return;
	visited[p][q] = true;
	if(p-1 >=0 && G[p-1][q]==1 && !visited[p-1][q])
		dfs(p - 1, q);
	if(p+1<n && G[p+1][q] == 1 && !visited[p + 1][q])
		dfs(p + 1, q);
	if(q+1 <m && G[p][q+1]==1 && !visited[p][q+1])
		dfs(p, q + 1);
	if(q-1 >=0 && G[p][q-1] == 1 && !visited[p][q-1])
		dfs(p, q - 1);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		int k, a,b;
		memset(visited, 0, sizeof(visited));
		memset(G, 0, sizeof(G));
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			G[b][a] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && G[i][j]==1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
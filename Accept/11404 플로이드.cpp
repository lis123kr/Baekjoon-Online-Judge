#include<stdio.h>
const int INF = 123456789;
int n, m,a,b,c;
int g[101][101];
int min(int a, int b) { return a > b ? b : a; }
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			g[i][j] = INF;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = min(g[a][b], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) continue;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", g[i][j] == INF ? 0 : g[i][j]);
		printf("\n");
	}
	return 0;
}
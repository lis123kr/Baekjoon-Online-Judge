#include<stdio.h>
int n, m,a,b,g[501][501], c[501],ans;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		g[b][a] = g[a][b] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (g[1][i]) {
			c[i] = 1;
			for (int j = 2; j <= n; j++) {				
				if (g[i][j])
					c[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
		if (c[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}
#include<stdio.h>
#include<string.h>
int n,q,parent[200001], pp[200001], query[400001][3], ans[200001];
int Find(int u) {
	if (parent[u] == u)
		return u;
	else
		return parent[u] = Find(parent[u]);
}
void Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	parent[v] = u;
}
int main() {
	scanf("%d %d", &n, &q);
	parent[1] = pp[1] = 1;
	for (int i = 2; i <= n; i++) {
		parent[i] = i;
		scanf("%d", &pp[i]);
	}
	for (int i = q + n - 1; i > 0; i--) {
		scanf("%d", &query[i][0]);
		if (query[i][0] == 1)
			scanf("%d %d", &query[i][1], &query[i][2]);
		else
			scanf("%d", &query[i][1]);
	}
	for (int i = 1, qq=1; i <= q + n-1; i++) {
		if (query[i][0] == 0) 
			Union(query[i][1], pp[query[i][1]]);		
		else {
			if (Find(query[i][1]) == Find(query[i][2]))
				ans[qq++] = 1;
			else
				ans[qq++] = 0;
		}
	}
	for (int i = q; i > 0; i--)
		printf("%s\n", ans[i] == 1 ? "YES" : "NO");
	return 0;
}
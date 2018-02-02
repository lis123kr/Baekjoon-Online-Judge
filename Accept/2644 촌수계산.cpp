#include<stdio.h>
#include<string.h>
struct Node {
	int parent;
}node[111];
int n, src, dst, m, a, b, visited[111];
int LCA(int s, int c, int f) {	
	if (visited[s]!=-1)
		return c + visited[s];
	if (node[s].parent == 0)
		return visited[s] = (f == 1 ? 0 : c);
	visited[s] = c;
	return LCA(node[s].parent, c + 1, f);
}
int main() {
	scanf("%d %d %d %d", &n, &src, &dst, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		node[b].parent = a;
	}
	memset(visited, -1, sizeof(visited));
	LCA(src, 0, 0);
	int ans = LCA(dst, 0, 1);
	if (src != dst)
		printf("%d\n", ans == 0 ? -1 : ans);
	else
		printf("0\n");
	return 0;
}
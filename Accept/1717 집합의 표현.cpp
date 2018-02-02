#include<stdio.h>
int n, m;
int parent[1000001];
int Find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = Find(parent[x]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	parent[b] = a;
}
int main() {
	int a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			Union(b, c);
		}
		else {
			if (Find(b) == Find(c)) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}
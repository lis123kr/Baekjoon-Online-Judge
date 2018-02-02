#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int>vec[50001];
bool visited[50001];
int n,m,a,b,depth[50001], parent[50001], p[50001][18];
int LCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	int log = 1;
	for (; (1 << log) <= depth[u]; log++);
	log--;
	for (int i = log; i >= 0; i--) {
		if (depth[u] - (1 << i) >= depth[v]) {
			u = p[u][i];
		}
	}
	if (u == v)
		return u;
	else {
		for (int i = log; i >= 0; i--) {
			if (p[u][i] != 0 && p[u][i] != p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		return parent[u];
	}	
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	visited[1] = true;
	parent[1] = 0;
	depth[1] = 0;
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (int x : vec[s]) {
			if (!visited[x]) {
				visited[x] = true;
				parent[x] = s;
				depth[x] = depth[s] + 1;
				q.push(x);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		p[i][0] = parent[i];
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
	return 0;
}
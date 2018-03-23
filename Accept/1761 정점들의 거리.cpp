#include<stdio.h>
#include<vector>
using namespace std;
struct nodes {
	int parent, depth, pdist;
	vector< pair<int,int> > child;
}node[40001];
int n, m;
vector< vector< pair<int,int> > > g(40001);
vector<bool>visited(40001);
void inline SWAP(int &u, int &v) { int tmp = u; u = v; v = tmp; }
void init(int p, int depth) {
	visited[p] = true;
	node[p].depth = depth;
	for (int i = 0; i < g[p].size(); i++) {
		if (!visited[g[p][i].first]) {			
			node[g[p][i].first].parent = p;
			node[g[p][i].first].pdist = g[p][i].second;
			node[p].child.push_back(g[p][i]);
			init(g[p][i].first, depth + 1);
		}
	}
}
int LCA(int u, int v) {
	int ans = 0;
	if (node[u].depth > node[v].depth) {
		SWAP(u, v);
	}
	while (node[u].depth != node[v].depth) {
		ans += node[v].pdist;
		v = node[v].parent;
	}
	while (node[u].parent != node[v].parent) {
		ans += node[u].pdist;
		ans += node[v].pdist;

		u = node[u].parent;
		v = node[v].parent;
	}
	if (u != v) ans += node[u].pdist + node[v].pdist;
	return ans;
}
int main() {
	scanf("%d", &n);
	int u, v, w;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &u, &v, &w);
		if (u > v) swap(u, v);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	init(2, 1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		printf("%d\n", LCA(u, v));
	}
	return 0;
}
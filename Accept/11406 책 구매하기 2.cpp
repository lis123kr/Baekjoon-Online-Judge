#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to, capacity;
		struct Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {};
	};
	vector< vector< Edge * > > graph;
	vector< bool > chk;
	int n, src, sink;
	MaximumFlow(int n, int src, int sink) : n(n), src(src), sink(sink) {
		graph.resize(n);
		chk.resize(n);
	}
	void addEdge(int u, int v, int c) {
		Edge *e1 = new Edge(v, c);
		Edge *e2 = new Edge(u, 0);
		e1->rev = e2;
		e2->rev = e1;
		graph[u].push_back(e1);
		graph[v].push_back(e2);
	}
	int dfs(int x, int c) {
		if (chk[x])
			return 0;
		chk[x] = true;
		if (sink == x)
			return c;
		for (int i = 0; i < graph[x].size(); i++) {
			if (graph[x][i]->capacity > 0) {
				int nc = graph[x][i]->capacity;
				if (c != 0 && nc > c) {
					nc = c;
				}
				int f = dfs(graph[x][i]->to, nc);
				if (f) {
					graph[x][i]->capacity -= f;
					graph[x][i]->rev->capacity += f;
					return f;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (true) {
			fill(chk.begin(), chk.end(), 0);
			int f = dfs(src, 0);
			if (f == 0)
				break;
			ans += f;
		}
		return ans;
	}
};
int main() {
	int a, n, m;
	scanf("%d %d", &n, &m);
	MaximumFlow mf(n + m + 2, 0, n + m + 1);
	for (int i = m + 1; i <= n + m; i++) {
		scanf("%d", &a);
		mf.addEdge(i, n + m + 1, a);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a);
		mf.addEdge(0, i, a);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = m + 1; j <= n + m; j++) {
			scanf("%d", &a);
			mf.addEdge(i, j, a);
		}
	}
	printf("%d\n", mf.flow());
	return 0;
}
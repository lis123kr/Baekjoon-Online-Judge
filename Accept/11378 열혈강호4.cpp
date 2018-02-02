#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to, c;
		struct Edge* rev;
		Edge(int to, int c) : to(to), c(c) {};
	};
	vector< vector< Edge *> > graph;
	vector<bool>chk;
	int n, src, sink;
	MaximumFlow(int n, int src, int sink) :n(n), src(src), sink(sink) {
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
		if (x == sink)
			return c;
		for (int i = 0; i < graph[x].size(); i++) {
			if (graph[x][i]->c > 0) {
				int nc = graph[x][i]->c;
				if (c != 0 && nc > c)
					nc = c;
				int f = dfs(graph[x][i]->to, nc);
				if (f) {
					graph[x][i]->c -= f;
					graph[x][i]->rev->c += f;
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
	int N, M, K, a, b;
	scanf("%d %d %d", &N, &M, &K);
	MaximumFlow mf(N + M + 3, 0, N + M + 2);
	mf.addEdge(0, N + M + 1, K);
	for (int i = 1; i <= N; i++) {
		mf.addEdge(0, i, 1);
		mf.addEdge(N + M + 1, i, K);
	}
	for (int i = N + 1; i <= N + M; i++)
		mf.addEdge(i, N + M + 2, 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &b);
			mf.addEdge(i, N + b, 1);
		}
	}
	printf("%d\n", mf.flow());
	return 0;
}
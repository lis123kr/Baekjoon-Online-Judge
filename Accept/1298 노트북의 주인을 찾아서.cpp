#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to, capacity;
		struct Edge *rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {};
	};
	int source, sink, n;
	vector< vector< Edge * > > graph;
	vector<bool>visited;
	MaximumFlow(int n, int source, int sink) :n(n), source(source), sink(sink) {
		graph.resize(n);
		visited.resize(n);
	};
	void add_Edge(int u, int v, int c) {
		Edge *e1 = new Edge(v, c);
		Edge *e2 = new Edge(u, 0);
		e1->rev = e2;
		e2->rev = e1;
		graph[u].push_back(e1);
		graph[v].push_back(e2);
	}
	int dfs(int x, int c) {
		if (visited[x])
			return 0;
		visited[x] = true;
		if (x == sink)
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
			fill(visited.begin(), visited.end(), false);
			int f = dfs(source, 0);
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	int source = 0, sink = n + n + 1;
	MaximumFlow mf(n + n + 2, source, sink);
	for (int i = 1; i <= n; i++) {
		mf.add_Edge(source, i, 1);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		mf.add_Edge(a, n + b, 1);
	}
	for (int i = 1; i <= n; i++) {
		mf.add_Edge(i + n, sink, 1);
	}
	cout << mf.flow() << endl;
	return 0;
}
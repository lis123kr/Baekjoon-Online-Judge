#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to, capacity;
		struct Edge* rev;
		Edge(int to, int capacity) :to(to), capacity(capacity) {};
	};
	vector< vector< Edge * > > graph;
	vector<bool>visited;
	int n, source, sink;
	MaximumFlow(int n, int source, int sink) :n(n), source(source), sink(sink) {
		graph.resize(n);
		visited.resize(n);
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
		if (visited[x])
			return 0;
		visited[x] = true;
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
			fill(visited.begin(), visited.end(), 0);
			int f = dfs(source, 0);
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
		mf.addEdge(N + M + 1, i, 1);
	}
	for (int i = N + 1; i <= N + M; i++) {
		mf.addEdge(i, N + M + 2, 1);
	}	
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
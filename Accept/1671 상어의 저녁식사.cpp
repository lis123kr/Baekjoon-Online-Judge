#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to, capacity;
		struct Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {}
	};
	int n, source, sink;
	vector< vector<Edge *> >graph;
	vector<bool>check;
	MaximumFlow(int n, int source, int sink) :n(n), source(source), sink(sink) {
		graph.resize(n);
		check.resize(n);
	}
	void addEdge(int u, int v, int c) {
		Edge *e1 = new Edge(v, c);
		Edge *e2 = new Edge(u, 0);
		e1->rev = e2;
		e2->rev = e1;
		graph[u].push_back(e1);
		graph[v].push_back(e2);
	}
	int dfs(int u, int c) {
		if (check[u])
			return 0;
		check[u] = true;
		if (sink == u)
			return c;
		for (int i = 0; i < graph[u].size(); i++) {
			if (graph[u][i]->capacity > 0) {
				int nc = graph[u][i]->capacity;
				if (c != 0 && nc > c) {
					nc = c;
				}
				int ret = dfs(graph[u][i]->to, nc);
				if (ret) {
					graph[u][i]->capacity -= ret;
					graph[u][i]->rev->capacity += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (true) {
			fill(check.begin(), check.end(), 0);
			int f = dfs(source, 0);
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};
int A[1001], B[1001], C[1001];
int main() {
	int n,a,b,c;
	scanf("%d", &n);
	MaximumFlow mf(2 * n + 2, 0, 2 * n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
	}
	for (int i = 1; i <= n; i++) {
		mf.addEdge(0, i, 2);
		mf.addEdge(i + n, 2 * n + 1, 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (A[i] >= A[j] && B[i] >= B[j] && C[i] >= C[j]) {
				if (A[i] == A[j] && B[i] == B[j] && C[i] == C[j]) {
					if(i>j)
						mf.addEdge(i, j + n, 1);
				}
				else {
					mf.addEdge(i, j + n, 1);
				}
			}
		}
	}
	printf("%d\n", n - mf.flow());
	return 0;
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to, capacity, data;
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
bool prime(int c) {
	if (c == 2) return true;
	for (int i = 2; i*i <= c; i++) {
		if (c%i == 0)return false;
	}
	return true;
}
int main() {
	int n, arr[50], first;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	vector< int > ans;
	for(int i=1;i<n;i++){
		if (!prime(arr[0] + arr[i]))
			continue;
		vector<int>even, odd;
		for (int j = 1; j < n; j++) {
			if (i == j)
				continue;
			if (arr[j] % 2 == 0)
				even.push_back(arr[j]);
			else
				odd.push_back(arr[j]);
		}
		if (even.size() != odd.size())
			continue;
		MaximumFlow mf(n, 0, n - 1);
		for (int j = 1; j <= odd.size(); j++) {
			mf.add_Edge(0, j, 1);
		}
		for (int j = odd.size() + 1; j <= odd.size() + even.size(); j++) {
			mf.add_Edge(j, n - 1, 1);
		}
		for (int p = 0; p < odd.size(); p++) {
			for (int q = 0; q < even.size(); q++) {
				if (prime(odd[p] + even[q])) {
					mf.add_Edge(p + 1, odd.size() + q + 1, 1);
				}
			}
		}
		if (mf.flow() == odd.size()) {
			ans.push_back(arr[i]);
		}
	}
	if (ans.size() == 0) {
		printf("-1\n");
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int tmp : ans) {
		printf("%d ", tmp);
	}
	printf("\n");
	return 0;
}
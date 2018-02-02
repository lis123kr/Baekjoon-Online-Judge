#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to, capacity;
		struct Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {};
	};
	int n, source, sink;
	vector< vector< struct Edge* > > graph;
	vector<bool>check;
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		check.resize(n);
	}
	void addEdge(int u, int v, int c) {
		struct Edge *ori = new Edge(v, c);
		struct Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int dfs(int x, int c) {
		if (check[x]) return 0;
		check[x] = true;
		if (x == sink)
			return c;
		for (int i = 0; i < graph[x].size(); i++) {
			if (graph[x][i]->capacity > 0) {
				int nc = graph[x][i]->capacity;
				if (c != 0 && c < nc) {
					nc = c;
				}
				int ret = dfs(graph[x][i]->to, nc);
				if (ret) {
					graph[x][i]->capacity -= ret;
					graph[x][i]->rev->capacity += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (true) {
			fill(check.begin(), check.end(), false);
			int ret = dfs(source, 0);
			if (ret == 0) break;
			ans += ret;
		}
		return ans;
	}
};

int node(string s) {
	if (s[0] >= 'A' && s[0] <= 'Z') {
		return s[0] - 'A';
	}
	else {
		return s[0] - 'a' + 26;
	}
}
int main() {
	int n;
	cin >> n;
	MaximumFlow mf(52, 0, 'Z' - 'A');
	for (int i = 0; i < n; i++) {
		string us, vs;
		int f;
		cin >> us >> vs >> f;
		int u = node(us), v = node(vs);
		mf.addEdge(u, v, f);
		mf.addEdge(v, u, f);
	}
	cout << mf.flow() << endl;
	return 0;
}
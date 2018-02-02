#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct MCMF {
	struct Edge {
		int to, capacity, cost;
		struct Edge *rev;
		Edge(int to, int capacity, int cost) :to(to), capacity(capacity), cost(cost) {};
	};
	int n, src, sink, inf = 1e9;
	vector< vector< Edge * > > graph;
	vector<bool>chk;
	vector<int>dist;
	vector< pair<int, int> >from;
	MCMF(int n, int src, int sink) :n(n), src(src), sink(sink) {
		graph.resize(n);
		chk.resize(n);
		dist.resize(n);
		from.resize(n, make_pair(-1, -1));
	}
	void addEdge(int u, int v, int cap, int cost) {
		Edge *e1 = new Edge(v, cap, cost);
		Edge *e2 = new Edge(u, 0, -cost);
		e1->rev = e2;
		e2->rev = e1;
		graph[u].push_back(e1);
		graph[v].push_back(e2);
	}
	void add_edge_from_src(int v, int cap, int cost) {
		addEdge(src, v, cap, cost);
	}
	void add_edge_to_sink(int u, int cap, int cost) {
		addEdge(u, sink, cap, cost);
	}
	bool SPFA(int &total_flow, int &total_cost) {
		fill(chk.begin(), chk.end(), 0);
		fill(dist.begin(), dist.end(), inf);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		dist[src] = 0;
		queue<int>q;
		q.push(src);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			chk[x] = false;
			for (int i = 0; i < graph[x].size(); i++) {
				auto e = graph[x][i];
				int to = e->to;
				if (e->capacity > 0 && dist[x] + e->cost < dist[to]) {
					dist[to] = dist[x] + e->cost;
					from[to] = make_pair(x, i);
					if (!chk[to]) {
						chk[to] = true;
						q.push(to);
					}
				}
			}
		}
		if (dist[sink] == inf)
			return false;
		int x = sink;
		int c = graph[from[x].first][from[x].second]->capacity;
		while (from[x].first != -1) {
			if (c > graph[from[x].first][from[x].second]->capacity)
				c = graph[from[x].first][from[x].second]->capacity;
			x = from[x].first;
		}
		x = sink;
		while (from[x].first != -1) {
			Edge *e = graph[from[x].first][from[x].second];
			e->capacity -= c;
			e->rev->capacity += c;
			x = from[x].first;
		}
		total_flow += c;
		total_cost += c*dist[sink];
		return true;
	}
	pair<int, int> flow() {
		int total_flow = 0, total_cost = 0;
		while (SPFA(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}
};
int N, M,a;
int main() {
	scanf("%d %d", &N, &M);
	MCMF mcmf(N + M + 2, 0, N + M + 1);
	for (int i = M+1; i <= N+M; i++) {
		scanf("%d", &a);
		mcmf.add_edge_to_sink(i, a, 0);
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &a);
		mcmf.add_edge_from_src(i, a, 0);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = M + 1; j <= M + N; j++) {
			scanf("%d", &a);
			mcmf.addEdge(i, j, 1000, a);
		}
	}
	auto ans = mcmf.flow();
	printf("%d\n", ans.second);
	return 0;
}
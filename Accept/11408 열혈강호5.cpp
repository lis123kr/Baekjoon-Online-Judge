#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct MCMF {
	struct Edge {
		int to, capacity, cost;
		struct Edge* rev;
		Edge(int to, int capacity, int cost) :to(to), capacity(capacity), cost(cost) {};
	};
	int n, src, sink, inf = 1e9;
	vector< vector < Edge * > > graph;
	vector< bool > chk;
	vector< int > dist;
	vector< pair<int, int> > from;
	MCMF(int n, int src, int sink) : n(n), src(src), sink(sink) {
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
	void add_Edge_from_src(int v, int cap, int cost) {
		addEdge(src, v, cap, cost);
	}
	void add_Edge_to_sink(int u, int cap, int cost) {
		addEdge(u, sink, cap, cost);
	}
	bool SPFA(int &total_flow, int &total_cost) {
		fill(chk.begin(), chk.end(), 0);
		fill(dist.begin(), dist.end(), inf);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		queue<int>q;
		q.push(src);
		dist[src] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			chk[cur] = false;
			for (int i = 0; i < graph[cur].size(); i++) {
				auto e = graph[cur][i];
				int to = e->to;
				if (e->capacity > 0 && dist[to] > dist[cur] + e->cost) {
					dist[to] = dist[cur] + e->cost;
					from[to] = make_pair(cur, i);
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
			graph[from[x].first][from[x].second]->capacity -= c;
			graph[from[x].first][from[x].second]->rev->capacity += c;
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
int main() {
	int a,b,c,n, m;
	scanf("%d %d", &n, &m);
	MCMF mcmf(n + m + 2, 0, n + m + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		mcmf.add_Edge_from_src(i, 1, 0);
		for (int j = 0; j < a; j++) {
			scanf("%d %d", &b, &c);
			mcmf.addEdge(i, n + b, 1000, c);
		}
	}
	for (int i = n + 1; i <= n + m; i++)
		mcmf.add_Edge_to_sink(i, 1, 0);
	auto e = mcmf.flow();
	printf("%d\n%d\n", e.first, e.second);
	return 0;
}
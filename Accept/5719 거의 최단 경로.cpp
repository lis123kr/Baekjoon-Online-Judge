#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		if (n == 0 && m == 0)
			break;
		int src, dst, u, v, p, ans;
		const int INF = 1e9;
		priority_queue< pair<int, int>, vector< pair<int, int> >> pq;
		vector< vector< pair<int, int> > > g(n);
		vector< int > dist(n, INF);
		vector< bool > visited(n, false), chk(n,false);
		vector< int > path(n,0);
		scanf("%d %d", &src, &dst);
		dist[src] = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &p);
			g[u].push_back(make_pair(-p, v));
		}		
		ans = dist[dst];
		while (ans == dist[dst]) {
			pq.push(make_pair(0, src));
			visited = vector<bool>(n, false);
			visited[src] = true;
			dist = vector<int>(n, INF);
			dist[src] = 0;
			while (!pq.empty()) {
				auto tmp = pq.top(); pq.pop();
				visited[tmp.second] = true;
				for (int i = 0; i < g[tmp.second].size(); i++) {
					if (!visited[g[tmp.second][i].second] && !chk[g[tmp.second][i].second]) {
						if (dist[g[tmp.second][i].second] >= dist[tmp.second] + (-g[tmp.second][i].first)) {
							dist[g[tmp.second][i].second] = dist[tmp.second] + (-g[tmp.second][i].first);
							path[g[tmp.second][i].second] = tmp.second;
							pq.push(make_pair(-dist[g[tmp.second][i].second], g[tmp.second][i].second));
						}
					}
				}
			}
			if (dist[dst] == INF) {
				printf("-1\n");
				break;
			}
			if (ans != INF && ans != dist[dst])
				break;
			ans = dist[dst];
			int x = dst;
			if (path[x] == src) {
				for (int i = 0; i < g[src].size(); i++) {
					if (g[src][i].second == dst)
						g[src][i].first = -INF;
				}
			}
			while (path[x] != src) {
				chk[path[x]] = true;
				x = path[x];
			}
		}
		if (dist[dst] != INF)
			printf("%d\n", dist[dst]);
	}
	return 0;
}
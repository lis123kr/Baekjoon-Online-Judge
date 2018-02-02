#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
	int to, cost;
	Edge(int to, int cost) : to(to), cost(cost){}
};
int dist[20001];
bool c[20001];
vector<Edge>ve[20001];
int main() {
	int v, e, src;
	scanf("%d %d %d", &v, &e, &src);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ve[a].push_back(Edge(b, c));
	}
	for (int i = 1; i <= v; i++) dist[i] = 1e9;
	priority_queue< pair<int, int> > pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int cur = p.second;
		if (c[cur]) continue;
		c[cur] = true;
		for (int i = 0; i < ve[cur].size(); i++) {
			int next = ve[cur][i].to;
			if (dist[next] > dist[cur] + ve[cur][i].cost) {
				dist[next] = dist[cur] + ve[cur][i].cost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == 1e9)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}
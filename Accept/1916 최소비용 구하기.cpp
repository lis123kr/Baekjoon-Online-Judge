#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
	int to, cost;
	Edge(int to,int cost) :to(to), cost(cost){}
};
int dist[1001];
vector<Edge>v[1001];
bool c[1001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(Edge(b, c));
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	int src, dst;
	scanf("%d %d", &src, &dst);
	dist[src] = 0;
	priority_queue< pair<int, int> >q;
	q.push(make_pair(0, src));
	while (!q.empty()) {
		auto t = q.top();
		q.pop();
		int cur = t.second;
		int w = t.first;
		if (c[cur]) continue;
		c[cur] = true;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].to;
			if (dist[next] > dist[cur] + v[cur][i].cost) {
				dist[next] = dist[cur] + v[cur][i].cost;
				q.push(make_pair(-dist[next], next));
			}
		}
	}
	printf("%d\n", dist[dst]);
	return 0;
}

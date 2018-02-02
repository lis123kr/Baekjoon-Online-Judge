// SPFA
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define INF	1e9
using namespace std;
int n, m, dist[501], cnt[501];
vector< pair<int,int> > v[501]; 
bool chk[501];
int main() {
	int a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	fill(dist, dist + 501, INF);
	dist[1] = 0;
	queue<int>q;
	q.push(1);
	chk[1] = true;
	while (!q.empty()) {
		int cur = q.front();
		chk[cur] = false; q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int to = v[cur][i].first, cost = v[cur][i].second;
			if (dist[to] > dist[cur] + cost) {
				dist[to] = dist[cur] + cost;
				if (!chk[to]) {
					q.push(to);
					chk[to] = true;
					cnt[to] += 1;
					if (cnt[to] >= n) {
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	}
	return 0;
}
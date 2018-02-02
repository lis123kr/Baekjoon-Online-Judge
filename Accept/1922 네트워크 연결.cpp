#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int G[1001][1001];
bool visited[1001];
int main() {
	scanf("%d %d", &n, &m);
	int a, b, c;
	memset(G, -1, sizeof(G));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		G[b][a] = G[a][b] = c;
	}
	priority_queue< pair<int,int> > pq;
	pq.push(make_pair(0, 1));
	int ans = 0;
	while (!pq.empty()) {
		int c_ = -pq.top().first, id = pq.top().second;
		pq.pop();
		if (visited[id]) continue;
		visited[id] = true;
		ans += c_;
		for (int i = 1; i <= n; i++) {
			if (i == id)continue;
			if (!visited[i] && G[id][i] != -1) {
				pq.push(make_pair(-G[id][i], i));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n, m, sink, src;
struct Edge {
	int to, capacity;
	struct Edge* rev;
	Edge(int to, int capacity) : to(to), capacity(capacity) {};
};
vector< Edge * > v[555];
bool visited[555];
int dfs(int x, int c) {
	if (visited[x])
		return 0;
	visited[x] = true;
	if (x == sink)
		return c;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i]->capacity > 0) {
			int nc = v[x][i]->capacity;
			if (c != 0 && nc > c)
				nc = c;
			int f = dfs(v[x][i]->to, nc);
			if (f) {
				v[x][i]->capacity -= f;
				v[x][i]->rev->capacity += f;
				return f;
			}
		}
	}
	return 0;
}
int flow() {
	int ans = 0;
	while (true) {
		fill(visited, visited + 555, 0);
		int f = dfs(src, 0);
		if (f == 0) break;
		ans += f;
	}
	return ans;
}
int main() {
	scanf("%d %d", &n, &m);
	sink = m + n + 1;
	for (int i = 1; i <= n; i++) {
		Edge *e1 = new Edge(i, 1);
		Edge *e2 = new Edge(0, 0);
		e1->rev = e2;
		e2->rev = e1;
		v[0].push_back(e1);
		v[i].push_back(e2);
		int f, t;
		scanf("%d", &f);
		for (int j = 0; j < f; j++) {
			scanf("%d", &t);
			e1 = new Edge(t+n, 1);
			e2 = new Edge(i, 0);
			e1->rev = e2;
			e2->rev = e1;
			v[i].push_back(e1);
			v[t+n].push_back(e2);
		}
	}
	for (int i = 1; i <= m; i++) {
		Edge *e1 = new Edge(sink, 1);
		Edge *e2 = new Edge(i + n, 0);
		e1->rev = e2;
		e2->rev = e1;
		v[i+n].push_back(e1);
		v[sink].push_back(e2);
	}
	printf("%d\n", flow());
	return 0;
}
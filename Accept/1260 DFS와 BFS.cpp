#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector< vector<int> > g;
bool visited[1001];

void DFS(int v) {
	visited[v] = true;
	printf("%d ", v);
	sort(g[v].begin(), g[v].end());
	for (int i = 0; i < g[v].size(); i++) {
		if (!visited[g[v][i]])
			DFS(g[v][i]);
	}
}

void BFS(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int next = q.front();		
		q.pop();		
		printf("%d ", next);
		sort(g[next].begin(), g[next].end());
		for (int i = 0; i < g[next].size(); i++) {
			if (!visited[g[next][i]]) {
				q.push(g[next][i]);
				visited[g[next][i]] = true;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, m, v, a, b;
	scanf("%d %d %d", &n, &m, &v);
	g = vector< vector<int> >(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	DFS(v);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	BFS(v);
	return 0;
}
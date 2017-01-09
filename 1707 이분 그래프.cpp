#include <cstdio>
#include <vector>
using namespace std;
int t;
vector< vector<int> > adj;
vector<int>visited;
bool dfs(int here, int set) {
	visited[here] = set;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (visited[there] == set) return false;
		if (visited[there] == 0 && !dfs(there, ~(set)+1)) return false;
	}
	return true;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		int v, e;
		bool result = true;
		scanf("%d %d", &v, &e);
		adj = vector<vector<int> >(v + 1);
		visited = vector<int>(v + 1, 0);
		for (int i = 1; i <= e; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) {
			if (visited[i] == 0) {
				if (!dfs(i, 1)) {
					result = false;
					break;
				}
			}
		}
		if (result) printf("YES\n");
		else printf("NO\n");
		adj.clear();
		visited.clear();
	}
	return 0;
}
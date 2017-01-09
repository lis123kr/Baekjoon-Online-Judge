#include<stdio.h>
#include<vector>
using namespace std;
int n, m;
vector< vector<int> > arr;
vector< bool > visited;
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < arr[v].size(); i++) {
		if (!visited[arr[v][i]])
			dfs(arr[v][i]);
	}
}
int dfs_all() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i), cnt++;
	}
	return cnt;
}
int main() {
	freopen("input.txt", "r", stdin);
	int a, b;
	scanf("%d %d", &n, &m);
	arr = vector< vector< int > >(n + 1);
	visited = vector< bool >(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	printf("%d", dfs_all());
	return 0;
}
#include<stdio.h>
#include<string.h>
int visited[100001], arr[100001];
void dfs(int x) {
	if (visited[x] == -1 || visited[x] == 18)
		return;
	visited[x]++;
	dfs(arr[x]);
}
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		memset(visited, 0, sizeof(visited));
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 && visited[arr[i]] == 0) {
				dfs(i);
				if(visited[i]!=18)
					visited[i] = -1;
			}
		}
		for (int i = 1; i <= n; i++)
			if (visited[i] == 18)
				ans++;
		printf("%d\n", n-ans);
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
struct Tree {
	int parent;
	vector< int > children;
}tree[1000001];
int n, dp[1000001][2];
bool visited[1000001];
int min(int a, int b) { return a > b ? b : a; }
int solve(int p, int s) {
	if (visited[p])
		return 0;
	visited[p] = true;
	if (dp[p][s] != -1)
		return dp[p][s];
	int h = 0;
	for (int i = 0; i < tree[p].children.size(); i++) {
		if (visited[tree[p].children[i]])
			continue;
		if (s) {			
			int tmp = solve(tree[p].children[i], 0);
			h += min(tmp, solve(tree[p].children[i], 1) + 1);
		}
		else {			
			h += solve(tree[p].children[i], 1) + 1;			
		}
	}
	visited[p] = false;
	return dp[p][s] = h;
}
int main() {
	int a, b, root=1; // 1은 그냥 설정한 값 / 아무대서나 시작해도 루트가 될 수 있음..
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		tree[b].children.push_back(a);
		tree[a].children.push_back(b);
	}
	int tmp = solve(root, 0);
	memset(visited, 0, sizeof(visited));
	int tmp1 = solve(root, 1) + 1;
	printf("%d\n", min(tmp, tmp1));
	return 0;
}
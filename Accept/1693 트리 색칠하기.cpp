#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
struct Nodes {
	vector< int > child;
}node[100001];
int inline min(int a, int b) { return a > b ? b : a; }
int n, dp[100001][20];
int solve(int p, int q, int parent) {
	if(node[p].child.size() == 1 && node[p].child[0] == parent)
		return q;
	if (dp[p][q] != -1)
		return dp[p][q];
	int h = 0;
	for (int i = 0; i < node[p].child.size(); i++) {
		if (node[p].child[i] == parent) continue;
		int tmp = 1e9;
		for (int c = 1; c < 20; c++) {
			if (c != q) {
				tmp = min(tmp, solve(node[p].child[i], c, p));
			}
		}
		h += tmp;
	}
	return dp[p][q] = h + q;
}
int main() {
	int a, b;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		node[a].child.push_back(b);
		node[b].child.push_back(a);
	}
	int ans = 1e9;
	for (int i = 1; i < 20; i++) {
		ans = min(ans, solve(a, i, a));
	}
	printf("%d\n", ans);
	return 0;
}
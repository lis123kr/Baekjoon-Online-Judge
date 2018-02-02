#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX	999999999
using namespace std;
int n, m;
int d[1001], w[1001];
int sum[1002];
int cache[1001][1001][2];
int dp(int x1, int x2, bool flag) {
	if (x1 == 1 && x2 == n) return 0;

	int &ret = cache[x1][x2][flag];
	if (ret != -1) return ret;

	ret = MAX;

	int cur = flag ? x1 : x2;

	if (x1 > 1) {
		int distance = d[cur] - d[x1 - 1];
		int waste = (sum[n+1] - sum[x2 + 1] + sum[x1]) * distance;
		ret = min(ret, waste + dp(x1 - 1, x2, true));
	}
	if (x2 < n) {
		int distance = d[x2 + 1] - d[cur];
		int waste = (sum[n+1] - sum[x2 + 1] + sum[x1]) * distance;
		ret = min(ret, waste + dp(x1, x2 + 1, false));
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 1; i <= n; i++) scanf("%d %d", &d[i], &w[i]);
	for (int i = 1; i <= n; i++) sum[i + 1] = sum[i] + w[i];
	memset(cache, -1, sizeof(cache));
	printf("%d", dp(m, m, false));
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n, m, arr[501][501], cache[501][501];
int dp(int p, int q) {
	if (p<1 || q<1 || p>n || q>m) return 0;
	if (p == 1 && q == 1) return 1;
	int &ret = cache[p][q];
	if (ret != -1) return ret;
	int h = 0;
	int v = arr[p][q];
	if (v < arr[p - 1][q]) h += dp(p - 1, q);
	if (v < arr[p][q - 1]) h += dp(p, q - 1);
	if (v < arr[p + 1][q]) h += dp(p + 1, q);
	if (v < arr[p][q + 1]) h += dp(p, q + 1);

	return ret = h;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &arr[i][j]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", dp(n, m));
	return 0;
}
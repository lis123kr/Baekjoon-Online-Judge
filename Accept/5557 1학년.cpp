#include<stdio.h>
#include<string.h>
int n, arr[101], ans;
long long cache[101][21];
long long dp(int p, int s) {
	if (p == n - 1 && s == ans) return 1;
	if (s < 0 || s > 20 || p > n-1) return 0;
	long long &ret = cache[p][s];
	if (ret > 0) return ret;
	return ret = dp(p + 1, s - arr[p]) + dp(p + 1, s + arr[p]);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	ans = arr[n - 1];
	memset(cache, -1, sizeof(cache));
	printf("%lld\n", dp(1, arr[0]));
	return 0;
}
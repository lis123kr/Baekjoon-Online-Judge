#include<cstdio>
#include<algorithm>
using namespace std;
int n, arr[101][101];
unsigned long long cache[101][101];
unsigned long long dp(int p, int q) {
	if (p == n && q == n) return 1;
	if (p > n || q > n || arr[p][q] == 0) return 0;
	unsigned long long &ret = cache[p][q];
	if (ret != 0) return ret;
	return ret = dp(p + arr[p][q], q) + dp(p, q + arr[p][q]);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &arr[i][j]);
	printf("%lld", dp(1, 1));
	return 0;
}
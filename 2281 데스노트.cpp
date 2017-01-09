#include<cstdio>
#include<algorithm>
#define INF 999999999
using namespace std;
int n, m, a[1001];
int cache[1001][1001];
unsigned long long dp(int p,int q) {
	if (q < 0)return INF;
	if (p == n)return 0;
	int &ret = cache[p][q];
	if (ret != 0)return ret;
	return ret = min(dp(p + 1, m-a[p+1]) + (q*q), dp(p + 1, q - 1 - a[p+1]));
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%lld", dp(0, m-a[0]));
	return 0;
}
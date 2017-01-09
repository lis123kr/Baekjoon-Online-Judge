#include<cstdio>
#include<algorithm>
#define INF 1e9
using namespace std;
int n, m, a[101],c[101];
//int cache[101][77778];
//현재 앱 번호, 남은 메모리
//답은 나오는데 캐쉬 메모리가 안되네.. 1<=M<=10,000,000
//int dp(int p, int q) {
//	if (p == n + 1)return INF;
//	if (q <= 0)return 0;
//	int &ret = cache[p][q % 77777];
//	if (ret != 0)return ret;
//	return ret = min(dp(p + 1, q), dp(p + 1, q - a[p])+c[p]);
//}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	int dp[10001] = { 0, };
	int mem = 0;
	for (int i = 1; i <= n; i++) {
		mem += c[i];
		for (int j = mem; j-c[i]>=0; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + a[i]);
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= m) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
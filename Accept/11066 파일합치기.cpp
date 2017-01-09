//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int n,t, A[501], S[501];
//int cache[501][501];
//int dp(int p, int q) {
//	if (p >= q) return 0;
//	if (p + 1 == q)return A[p] + A[q];
//	int &ret = cache[p][q];
//	if (ret < 2e9) return ret;
//	for (int i = p; i < q; i++)
//		ret = min(ret, dp(p, i) + dp(i + 1, q) + S[q] - S[p - 1]);
//	return ret;
//
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d", &n);
//		for (int i = 1; i <= n; i++) { scanf("%d", &A[i]); S[i] = S[i - 1] + A[i]; }
//		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)cache[i][j] = 2e9;
//		printf("%d\n", dp(1, n));
//	}
//	return 0;
//}
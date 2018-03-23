//#include<stdio.h>
//#include<string.h>
//int n, k, dp[201][201], arr[201];
//int inline min(int a, int b) { return a < b ? a : b; }
//int solve(int p, int q) {
//	if (p >= q) return 0;
//	if (dp[p][q] != -1)
//		return dp[p][q];
//	int h, pp = p, qq = q;	
//	while (arr[pp] == arr[pp + 1])
//		pp++;
//	pp++;
//	while (arr[qq] == arr[qq - 1])
//		qq--;
//	qq--;
//	if (pp > qq) 
//		return dp[p][q] = 0;
//	h = solve(pp, q) + 1;
//	h = min(h, solve(p, qq) + 1);
//	if (arr[p] == arr[q]) {
//		h = min(h, solve(pp, qq) + 1);
//	}
//	return dp[p][q] = h;
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	printf("%d\n", solve(0, n - 1));
//	return 0;
//}
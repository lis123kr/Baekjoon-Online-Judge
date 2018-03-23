//#include<stdio.h>
//#include<string.h>
//int t, n, w, arr[2][10001], dp[10001][4][4];
//int inline max(int a, int b) { return a > b ? a : b; }
//int solve(int p,int s, int e) {
//	if (p == n - 1) {
//		if ((s == 1 || s == 3) && (e == 1 || e== 3) && arr[0][p] + arr[0][p - 1] <= w) return 1;
//		else if ((s>1) &&(e == 2 || e==3) && arr[1][p] + arr[1][p - 1] <= w) return 1;
//		else if ( e == 3 && arr[0][p] + arr[1][p] <= w)return 1;
//		else return 0;
//	}
//	if (dp[p][s][e] != -1)
//		return dp[p][s][e];
//	int h = 0;
//	h = max(h, solve(p + 1, 3, e));
//	if (arr[0][p] + arr[1][p] <= w) {
//		h = max(h, solve(p + 1, 0, e) + 1);
//	}
//	if (s == 3) {
//		if (arr[0][p] + arr[0][p - 1] <= w) {
//			h = max(h, solve(p + 1, 2, e) + 1);
//			if (arr[1][p] + arr[1][p - 1] <= w) {
//				h = max(h, solve(p + 1, 0, e) + 2);
//			}
//		}
//	}
//	if (s == 1) { 
//		if (arr[0][p] + arr[0][p - 1] <= w) {
//			h = max(h, solve(p + 1, 2, e) + 1);
//		}
//	}
//
//	if (s == 2) {
//		if (arr[1][p] + arr[1][p - 1] <= w) {
//			h = max(h, solve(p + 1, 1, e) + 1);
//		}
//	}
//	return dp[p][s][e] = h;
//}
//int main() {
//	scanf("%d", &t);
//	while (t--) {
//		memset(dp, -1, sizeof(dp));
//		scanf("%d%d", &n, &w);
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < n; j++) {
//				scanf("%d", &arr[i][j]);
//			}
//		}
//		if (n == 1) {
//			printf("%d\n", arr[0][0] + arr[1][0] <= w ? 1 : 2);
//			continue;
//		}
//		int ans = 0;
//		ans = max(ans, solve(1, 3, 3));
//		if (arr[0][n - 1] + arr[0][0] <= w) {
//			ans = max(ans, solve(1, 2, 2) + 1);
//			if (arr[1][n - 1] + arr[1][0] <= w) {
//				ans = max(ans, solve(1, 0, 0) + 2);
//			}
//		}
//		if (arr[1][n - 1] + arr[1][0] <= w) {
//			ans = max(ans, solve(1, 1, 1) + 1);
//		}
//
//		if (arr[0][0] + arr[1][0] <= w) {
//			ans = max(ans, solve(1, 0, 3) + 1);
//		}
//		
//		printf("%d\n", (n * 2 - ans * 2) + ans);
//	}
//	return 0;
//}
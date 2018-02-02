#include<stdio.h>
#include<math.h>
#include<string.h>
const int INF = 999999999;
double m;
int n, A[5001], dp[10001], cal[5001];
int max(int a, int b) { return a > b ? a : b; }
int go(int qq) {
	if (qq < 0) return -INF;
	if (qq==0) return 0;
	if (dp[qq] > 0)
		return dp[qq];
	for (int i = 0; i < n; i++) {
		dp[qq] = max(dp[qq], go(qq - A[i]) + cal[i]);
	}
	return dp[qq];
}
int main() {
	while (1) {
		memset(dp, 0, sizeof(dp));
		memset(cal, 0, sizeof(cal));
		memset(A, 0, sizeof(A));
		scanf("%d %lf", &n, &m);
		if (n == 0 && m == 0.00) break;
		for (int i = 0; i < n; i++) {
			double t;
			scanf("%d %lf", &cal[i], &t);
			A[i] = (int)(t * 100 + 0.5); // +0.5 : 형변환 -> 버림
		}
		printf("%d\n", go((int)(m*100+0.5)));
	}
	return 0;
}
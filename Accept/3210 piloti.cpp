#include <stdio.h>
#include <string.h>
const int INF = 999999999;
int n, ans[5001], ans2[5001], cap[10001], assi[10001];
int min(int a, int b) { return a > b ? b : a; }
int solve() {
	for (int piloti = 1; piloti < n/2; piloti++)
		ans[piloti] = INF;
	ans[0] = assi[0];
	for (int piloti = 1; piloti < n; piloti++) {
		for (int ncap = 0; ncap <= n/2; ncap++) {
			int mincap, minassi;
			ans2[ncap] = INF;

			// captain 수가 많거나 부족할 때 INF
			if ((piloti + 1) / 2 < ncap || (piloti + 1) > n / 2 + ncap)
				continue;			

			if (ncap != 0 && ans[ncap - 1] != INF)
				mincap = ans[ncap - 1] + cap[piloti];
			else
				mincap = INF;

			if (ans[ncap] != INF)
				minassi = ans[ncap] + assi[piloti];
			else
				minassi = INF;

			ans2[ncap] = min( mincap, minassi );
		}
		// 저장한 이전 상황 업데이트
		memcpy(ans, ans2, sizeof(ans));
	}
	return ans[n / 2];
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &cap[i], &assi[i]);
	printf("%d\n", solve());
	return 0;
}

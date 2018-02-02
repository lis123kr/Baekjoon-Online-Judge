#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int A[20][20], dp[1<<20][17];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j =0; j < n; j++) scanf("%d", &A[i][j]);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 99999999;
		}
	}
	dp[1][0] = 0;
	for (int i = 0; i < (1<<n); i++) {
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				for (int k = 0; k < n; k++) {
					if (A[k][j] != 0 && j != k && (i&(1 << k))) {
						dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + A[k][j]);
					}
				}
			}
		}
	}
	int ans = 99999999;
	for (int i = 0; i < n; i++) {
		if (A[i][0]) {
			ans = min(ans, dp[(1 << n) - 1][i] + A[i][0]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
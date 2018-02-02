#include<stdio.h>
int t, k, n, arr[15][15];
int main() {
	scanf("%d", &t);
	for (int i = 1; i <= 14; i++)
		arr[0][i] = i;
	for (int i = 1; i <= 14; i++) {
		int cnt = 0;
		for (int j = 1; j <= 14; j++) {
			cnt += arr[i - 1][j];
			arr[i][j] = cnt;
		}
	}
	while (t--) {
		int ans = 0;
		scanf("%d %d", &k, &n);
		for (int i = 1; i <= n; i++)
			ans += arr[k - 1][i];
		printf("%d\n", ans);
	}
	return 0;
}
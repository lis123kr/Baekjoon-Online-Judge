#include<stdio.h>
const int INF = 999999999;
int n, arr[300], dp[300001];
int main() {
	int s = 0,ps=0;
	scanf("%d", &n);
	for (int i = 1; i <= 300000; i++)
		dp[i] = INF;
	for (int i = 1; i <= 150; i++) {
		s += i;
		arr[i] = ps + s;
		if (arr[i] > 300000)
			break;
		dp[arr[i]] = 1;
		ps = arr[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; i - arr[j] >= 0; j++) {
			if (dp[i] > dp[i - arr[j]] + 1) {
				dp[i] = dp[i - arr[j]] + 1;
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
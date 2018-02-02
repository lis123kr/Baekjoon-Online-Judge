#include<stdio.h>
int arr[101], dp[10001];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - arr[i] >= 0)
				dp[j] += dp[j - arr[i]];
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}
#include<stdio.h>
#include<string.h>
int dp[100001];
int arr[100001], sum[100001];
int main() {
	int n, s, sub=0;
	scanf("%d %d", &n, &s);

	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
		sub += arr[i];
		sum[i] = sub;
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (sum[i] - sum[j] >= s) {
				dp[i] = i - j;
				break;
			}
		}
	}
	int ans = 111111;
	for (int i = 1; i <= n; i++) {
		if (ans > dp[i] && dp[i] != -1)
			ans = dp[i];
	}
	if (ans == 111111) printf("0\n");
	else printf("%d\n", ans);
	return 0;
}
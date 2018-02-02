#include<stdio.h>
long long arr[100], dp[100];
int main() {
	int n;
	dp[1] = arr[1] = 1LL;
	dp[2] = arr[2] = 3LL;
	scanf("%d", &n);
	for (int i = 3; i <= 30; i++) {
		arr[i] = arr[i - 1] + 2LL * arr[i - 2];
	}
	for (int i = 3; i <= 30; i++) {
		long long tmp = 0;
		if (i % 2 == 1) tmp = arr[(i - 1) / 2];
		else tmp = arr[i / 2] + 2 * arr[(i - 2) / 2];
		dp[i] = (arr[i] + tmp) / 2;
	}
	printf("%lld\n", dp[n]);
	return 0;
}
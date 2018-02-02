#include<stdio.h>
unsigned int dp[1001] = { 1,1,5, 11};
int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 4; i<1000; i++) {
		dp[i] = dp[i - 1] + 4 * dp[i - 2];
		for (int j = 4; i - j >= 0; j += 2) {
			dp[i] += 3 * dp[i - j] + 2 * dp[i - j + 1];
		}
		if (i % 2 == 1)
			dp[i] += 2;
	}
	while (t--) {
		scanf("%d", &n);		
		printf("%d\n", dp[n]);
	}
	return 0;
}
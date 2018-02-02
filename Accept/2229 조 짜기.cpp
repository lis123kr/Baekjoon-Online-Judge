#include<stdio.h>
#include<string.h>
#include<math.h>
int n, arr[1001], d[1001];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int dp(int p) {
	if (d[p] != -1)
		return d[p];
	int ans = 0;
	int MAX = max(arr[p], arr[p - 1]);
	int MIN = min(arr[p], arr[p - 1]);
	for (int i = 1; i < p; i++) {
		if (arr[p - i] > MAX)
			MAX = arr[p - i];
		else if (arr[p - i] < MIN)
			MIN = arr[p - i];
		ans = max(ans, dp(p - i - 1) + MAX - MIN);
	}
	return d[p] = ans;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	d[1] = abs(arr[1] - arr[0]);
	printf("%d\n", dp(n-1));
	return 0;
}
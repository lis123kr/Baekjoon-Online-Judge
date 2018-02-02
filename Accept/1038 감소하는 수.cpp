#include<stdio.h>
#include<string.h>
#include<math.h>
int N;
long long cache[11][11];
long long nCr(int n, int r) {
	long long &ret = cache[n][r];
	if (n == r || r == 0) return ret=1;
	else if (r == 1) return ret = n;
	if (ret != -1) return ret;
	return ret = nCr(n - 1, r - 1) + nCr(n - 1, r);
}
long long dp(int n, int r, int ans) {
	if (r <= 1) return ans-1;

	int high = r - 2;
	while (true) {
		high++;
		int sub = nCr(high, r - 1);
		if (ans > sub) ans -= sub;
		else break;
	}
	long long res = high * (long long)pow(10, r - 1) + dp(high - 1, r - 1, ans);
	return res;
}
int main() {
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	N++;
	long long sum = 10;
	int s = 0;
	int digit = 0;
	while (true) {
		digit++;
		if (digit > 10) {
			printf("-1");
			return 0;
		}
		s = nCr(10, digit);
		if (N > s) {
			N -= s;
			continue;
		}
		else break;
	}
	printf("%lld", dp(9, digit, N));
	return 0;
}
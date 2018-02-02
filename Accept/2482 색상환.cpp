#include<stdio.h>
#include<string.h>
#define	mod 1000000003
int n, k;
int cache[1001][1001];
int solve(int N, int K) {
	if (N < 1 || K < 1) return 0;
	int &ret = cache[N][K];
	if (ret != -1) return ret;
	if (K == 1) return ret = N;
	else if (K * 2 > n + 1) return ret = 0;
	else {
		return ret = (solve(N - 1, K) + solve(N - 2, K - 1)) % mod;
	}
}
int main() {
	scanf("%d %d", &n, &k);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", k==1 ? n: (solve(n-3, k-1) + solve(n-1,k)) % mod);
	return 0;
}
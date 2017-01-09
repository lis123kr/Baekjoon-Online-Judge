#include <iostream>
#include <cstdio>
#include <string.h>
#define MIN_VALUE 9999999
using namespace std;
int n, arr[1001];
int cache[1001];
int Min(int a, int b) { return a > b ? b : a; }
// D(p) = Min (  D( p+arr[p], D( p+arr[p]-1, D( p+arr[p]-2 ... D( p+1 ) )
int dp(int p) {
	int h = MIN_VALUE;
	int &ret = cache[p];
	if (p > n) return MIN_VALUE;
	if (p == n) return 0;
	if (ret != -1) return ret;
	for (int i = 1; i <= arr[p]; i++)
		h = Min(h, dp(p + i));
	return ret=h+1;
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	memset(cache, -1, sizeof(cache));
	int result = dp(1);
	printf("%d\n", result < MIN_VALUE ? result : -1);
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n, A[2001],B[2001], cache[2001][2001];
int dp(int a, int b) {
	if (b >= n) return 0;
	if (a >= n) return 0;
	int &ret = cache[a][b];
	if (ret != -1) return ret;
	int h = 0;
	if (A[a] > B[b]) h = max(h, dp(a, b + 1) + B[b]);
	h = max(h, dp(a + 1, b + 1));
	h = max(h, dp(a + 1, b));
	return ret = h;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 0; i < n; i++) scanf("%d", &B[i]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", dp(0, 0));
	return 0;
}
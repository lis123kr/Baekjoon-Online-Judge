#include<stdio.h>
#include<string.h>
#define	INF	99999999
int n;
int src[100001], dst[100001], ori[100001];
int min(int a, int b) { return a > b ? b : a; }
int solve(int p) {	
	if (p == n) return src[p - 1] == dst[p - 1] ? 0 : INF;
	int a = src[p - 1], b = src[p], c = src[p + 1];
	int cnt = 0;
	if (src[p - 1] != dst[p - 1]) {
		src[p - 1] = src[p - 1] == 0 ? 1 : 0;
		src[p] = src[p] == 0 ? 1 : 0;
		src[p + 1] = src[p + 1] == 0 ? 1 : 0;
		cnt = 1;
	}
	return solve(p + 1) + cnt;	
}
int main() {	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%1d", &src[i]);
	for (int i = 0; i < n; i++) scanf("%1d", &dst[i]);
	memcpy(ori, src, sizeof(src));
	int ans = solve(1);
	memcpy(src, ori, sizeof(src));
	src[0] = src[0] == 0 ? 1 : 0;
	src[1] = src[1] == 0 ? 1 : 0;
	ans = min(ans, solve(1)+1);
	printf("%d\n", ans>=INF ? -1 : ans);
	return 0;
}
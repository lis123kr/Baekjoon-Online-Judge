#include<stdio.h>
#include<string.h>
int n, m;
int C[1001][1001];
int cache[1001][1001];
int Max(int a, int b) {
	return a > b ? a : b;
}
//D(i,j) = Max(D(i+1,j), D(i,j+1), D(i+1, j+1)) + C[i][j]
// Àç±Í
int dp(int i, int j) {
	if (i > n || j > m) return 0;
	if (cache[i][j] != -1) return cache[i][j];
	return cache[i][j] =Max(dp(i+1,j), dp(i,j+1)) + C[i][j];
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for(int j=1;j<=m;j++)
			scanf("%d", &C[i][j]);
	// ¹Ýº¹¹®
	//for(int i=1;i<=m;i++)
	//	C[1][i] += C[1][i - 1];

	//for (int i = 1; i <= n-1; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		C[i + 1][j] += C[i + 1][j - 1] > C[i][j] ? C[i + 1][j - 1] : C[i][j];
	//	}
	//}
	printf("%d\n", dp(1,1));
	return 0;
}
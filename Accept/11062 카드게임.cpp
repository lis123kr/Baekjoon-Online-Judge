#include<stdio.h>
#include<string.h>
int t, n, A[1001], D[1001][1001][2];
// 0 근우 , 1 명우
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }
int dp(int p, int q, int s) {
	if (p == q && s == 0)
		return A[p];z
	else if (p == q && s == 1)
		return 0;
	if (D[p][q][s] != -1) return D[p][q][s];
	if (s == 0) {
		D[p][q][s] = max(dp(p + 1, q, 1) + A[p], dp(p, q - 1, 1) + A[q]);
	}
	else {
		D[p][q][s] = min(dp(p + 1, q, 0), dp(p, q - 1, 0));
	}
	return D[p][q][s];
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(D, -1, sizeof(D));
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		
		printf("%d\n", dp(1, n, 0));
	}
	return 0;
}
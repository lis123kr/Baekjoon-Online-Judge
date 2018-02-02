#include<stdio.h>
int A[222], P[222], D[222][222], n;
int max(int a, int b) { return a > b ? a : b; }
int solve(int p) {
	if (p > n) return 0;
	int ans = solve(p+1);
	for (int i = p; i <= n; i++) {
		if (A[i] <= n+1) {
			ans = max(ans, solve(A[i]) + P[i]);
		}
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &A[i], &P[i]);
		A[i] += i;
	}
	printf("%d\n", solve(1));
	return 0;
}
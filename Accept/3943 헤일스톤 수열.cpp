#include<stdio.h>
int D[300003];
int max(int a, int b) { return a > b ? a : b; }
int solve(int n) {
	if (n == 1)
		return 1;
	if (n<= 300000 && D[n] != 0) 
		return D[n];
	if(n<=300000)
		return D[n] = n%2 ? max(n, solve(3*n+1)) : max(n, solve(n / 2));
	else
		return n % 2 ? max(n, solve(3 * n + 1)) : max(n, solve(n / 2));
}
int main() {
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
}
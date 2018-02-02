#include<stdio.h>
int N, r, c;
int solve(int n, int y,int x) {
	if (n == 1) {
		return 2 * (r - y) + (c - x);
	}
	else {
		int s = 1 << n, s2 = (s/2) *(s/2);
		if (r < y + (s / 2)) {
			if (c < x + (s / 2)) {
				return solve(n - 1, y, x);
			}
			else {
				return solve(n - 1, y, x + (s / 2)) + s2;
			}
		}
		else {
			if (c < x + (s / 2)) {
				return solve(n - 1, y + (s / 2), x) + 2 * s2;
			}
			else {
				return solve(n - 1, y + (s / 2), x + (s / 2)) + 3 * s2;
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &r, &c);
	printf("%d\n", solve(N, 0, 0));
	return 0;
}
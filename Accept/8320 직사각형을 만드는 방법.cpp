#include<stdio.h>
int n,ans;
int solve(int c) {
	int cnt = 1;
	for (int i = 2; i*i <= c; i++) {
		if (c%i == 0) {
			cnt += 1;
		}
	}
	return cnt;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ans += solve(i);
	}
	printf("%d\n", ans);
	return 0;
}
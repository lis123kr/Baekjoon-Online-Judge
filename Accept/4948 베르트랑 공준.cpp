#include<stdio.h>
#define NUM 123456
int n, prime[NUM*2+1];
int main() {
	for (int i = 3; i <= NUM * 2; i++) {
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				prime[i] = 1;
				break;
			}
		}
	}
	prime[1] = 1;
	while (scanf("%d", &n)) {
		int ans = 0;
		if (n == 0)
			break;
		for (int i = n+1; i <= 2 * n; i++) {
			if (!prime[i])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
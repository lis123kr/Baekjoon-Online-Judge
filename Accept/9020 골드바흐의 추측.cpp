#include<stdio.h>
#define NUM 10000
int n, t, prime[NUM+1];
int main() {
	scanf("%d", &t);
	prime[1] = 1;
	for (int i = 3; i <= NUM; i++) {
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				prime[i] = 1;
				break;
			}
		}
	}	
	while (t--) {
		scanf("%d", &n);
		int a, b;
		for (a = n / 2, b = n / 2; ; a--, b++) {
			if (!prime[a] && !prime[b]) {
				printf("%d %d\n", a, b);
				break;
			}
		}
	}
	return 0;
}
#include<stdio.h>
int n, m;
int prime[10001] = { 0,0,1,1 };
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 4; i <= 10000; i++) {
		int f = 1;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				f = 0;
				break;
			}			
		}
		if(f==1)
			prime[i] = 1;
	}
	int ans = 0, min;
	for (int i = m; i <= n; i++) {
		if (prime[i]==1) {
			if (ans == 0) min = i;
			ans += i;
		}
	}
	if (ans == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n%d\n", ans, min);
	}
	return 0;
}
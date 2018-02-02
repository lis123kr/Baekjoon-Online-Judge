#include<stdio.h>
#include<math.h>
int n;
int isprime(int p) {
	if (p == 1) return 0;
	int e = (int)sqrt(p);
	for (int i = 2; i <= e; i++) {
		if (p%i == 0) return 0;
	}
	return 1;
}
void go(int p, int q) {
	if (p == n) {
		printf("%d\n", q);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int qq = q * 10 + i;
		if (isprime(qq) == 1) {
			go(p + 1, qq);
		}
	}
}
int main() {	
	scanf("%d", &n);
	int s = (int)pow(10, n - 1), e = (int)pow(10, n);
	go(0, 0);
	return 0;
}
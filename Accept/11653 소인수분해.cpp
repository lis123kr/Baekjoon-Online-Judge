#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) printf("1");
	for (int i = 2; n / i > 0; i++) {
		while (n%i == 0) { printf("%d\n", i); n /= i; }
	}
	return 0;
}
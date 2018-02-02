#include<stdio.h>
int n, D[1000001];
const int MOD = 1000000000;
int main() {
	scanf("%d", &n);
	D[0] = D[1] = 1;
	for (int i = 1; i <= n; i *= 2) {
		for (int j = 2; j <= n; j++) {
			if (j - i >= 0)
				D[j] += D[j - i];
			D[j] %= MOD;
		}
	}
	printf("%d\n", D[n]);
	return 0;
}
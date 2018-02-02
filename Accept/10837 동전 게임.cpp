#include<stdio.h>
int m, n, k, c;
int main() {
	scanf("%d %d", &k, &c);
	for (int i = 0; i < c; i++) {
		scanf("%d %d", &m, &n);
		if (m == n || m == n - 1) {
			printf("1\n");
			continue;
		}
		if (k % 2 == 0) {
			if (m > n) {
				printf("%d\n", (k + n >= m + m - 2) ? 1 : 0);
			}
			else {
				printf("%d\n", (k + m >= n + n - 1) ? 1 : 0);
			}
		}
		else {
			if (m > n) {
				printf("%d\n", (k + n >= m + m - 2) ? 1 : 0);
			}
			else {
				printf("%d\n", (k + m >= n + n - 1) ? 1 : 0);
			}
		}
	}
	return 0;
}
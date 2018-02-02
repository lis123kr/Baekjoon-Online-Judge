#include<stdio.h>
int arr[2001],c[2001];
int main() {
	int d1, d2, ans = 0;
	scanf("%d %d", &d1, &d2);
	for (int i = 1; i <= 2000; i++) {
		arr[i] = i;
		for (int j = 1; j < i; j++) {
			if (i%j == 0) {
				arr[i] -= arr[j];
			}
		}
	}
	for (int i = d1; i <= d2; i++) {
		ans += i;
		for (int j = 1; j < i; j++) {
			if (i % j == 0 && c[j] == 1)
				ans -= arr[j];
			if (i%j == 0) {
				c[j] = 1;
			}
		}
		c[i] = 1;
	}

	printf("%d\n", ans);
	return 0;
}
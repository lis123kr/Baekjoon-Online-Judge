#include<stdio.h>
int n, x[55], y[55];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	for (int i = 0; i < n; i++) {
		int ans = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (x[i] < x[j] && y[i] < y[j])
				ans++;
		}
		printf("%d ", ans);
	}
	return 0;
}
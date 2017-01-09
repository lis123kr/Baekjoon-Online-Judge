#include <cstdio>

int n;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int a[1001],b[1001],c[1001];
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int max = 0;
		b[i] = 1;
		for (int j = i - 1; j > 0; j--) {
			if (a[i] > a[j]) {
				max = b[j] > max ? b[j] : max;
				b[i] = max + 1;
			}			
		}
	}
	for (int i = n; i >0; i--) {
		int max = 0;
		c[i] = 1;
		for (int j = i +1; j <=n; j++) {
			if (a[i] > a[j]) {
				max = c[j] > max ? c[j] : max;
				c[i] = max + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		max = max > b[i] + c[i] ? max : b[i] + c[i];
	}
	printf("%d", max-1);
	return 0;
}
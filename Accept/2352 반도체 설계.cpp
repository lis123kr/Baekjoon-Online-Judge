#include<cstdio>
int n;
int port[40001];
int c[40001];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &port[i]);
	for (int i = 1; i <= n; i++) {
		int max = c[i] = 1;		
		for (int j = i - 1; j > 0; j--) {
			if (port[i] > port[j]) {
				max = max > c[j] ? max : c[j];
				c[i] = max + 1;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) if (result < c[i]) result = c[i];
	printf("%d", result);
	return 0;
}
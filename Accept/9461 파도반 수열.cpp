#include <cstdio>

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	unsigned long long c[101] = { 0,1,1,1,2,2 };
	for (int i = 6; i <= 100; i++) {
		c[i] = c[i - 1] + c[i - 5];
	}
	for (int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", c[n]);
	}
	return 0;
}
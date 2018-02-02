#include<stdio.h>
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int cnt = 0;
	while (n + m - 3 >= k) {
		if (n - 2 >= 0 && m - 1 >= 0) cnt++;
		n -= 2;
		m -= 1;
	}
	printf("%d\n", cnt);
	return 0;
}
#include<stdio.h>
int main() {
	int n, ans = 0;;
	scanf("%d", &n);
	while (n > 0) {
		if (n % 5 == 0) {
			ans += n / 5;
			n %= 5;
		}
		else {
			n -= 3;
			ans++;
		}
	}
	if (n == 0) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}
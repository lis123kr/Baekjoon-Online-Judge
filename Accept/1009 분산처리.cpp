#include<stdio.h>
typedef long long LL;
LL solve(LL a, LL b) {
	if (a == 1 || b == 0) return 1LL;
	if (b == 1) return a;
	if (b % 2 == 1) return (a*(solve(a, b - 1) % 10LL))%10LL;
	else {
		LL m1 = solve(a, b / 2) % 10LL;
		return (m1 * m1) % 10LL;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		long long ans = solve(a, b) % 10LL;
		printf("%lld\n", ans == 0 ? 10LL : ans);
	}
	return 0;
}
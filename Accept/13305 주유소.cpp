#include<stdio.h>
typedef unsigned long long ull;
int n, dist[100001], c, pc=1e9+5;
ull ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
		scanf("%d", &dist[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		pc = c > pc ? pc : c;
		ans += (ull)pc * (ull)dist[i];
	}
	printf("%lld\n", ans);
	return 0;
}
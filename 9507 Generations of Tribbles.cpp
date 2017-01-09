#include <cstdio>
int n;
unsigned long long cache[100];
unsigned long long dp(int m) {
	unsigned long long &ret = cache[m];
	if (ret != 0) return ret;
	if (m < 2) return ret = 1;
	else if (m == 2) return ret = 2;
	else if (m == 3) return ret = 4;
	else return ret = dp(m - 1) + dp(m - 2) + dp(m - 3) + dp(m - 4);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int t;
	for (int i = 0; i < n; i++)	{
		scanf("%d", &t);
		printf("%lld\n", dp(t));
	}
	return 0;
}
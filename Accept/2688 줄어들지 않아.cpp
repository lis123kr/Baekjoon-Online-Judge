#include<cstdio>
#include<cstring>
int t, n;
unsigned long long cache[111][11];
//���� �д� �ڸ���, ���� �ڸ��� ����ġ
unsigned long long dp(int p, int q) {
	if (p == n + 1 || q == 9) return 1;
	unsigned long long &ret = cache[p][q];
	if (ret != 0) return ret;
	unsigned long long h = 0;
	for (int i = q; i < 10; i++)
		h += dp(p + 1, i);
	return ret = h;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%lld\n", dp(1, 0));
		memset(cache, 0, sizeof(cache));
	}
	return 0;
}
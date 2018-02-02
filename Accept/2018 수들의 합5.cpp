#include<stdio.h>
typedef long long LL;
LL n;
LL chk(LL N, LL K) {
	if ((N - K) * (N + K + 1) > 2 * n)
		return 1;
	else if ((N - K) * (N + K + 1) == 2 * n)
		return 0;
	else
		return -1;
}
int main() {
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 1; i < n; i++) {
		LL left = 0, right = i;
		while (left <= right) {
			LL mid = (left + right) / 2;
			LL c = chk(i, mid);
			if (c == 1) {
				left = mid + 1;
			}
			else if(c==-1){
				right = mid - 1;
			}
			else {
				ans += 1LL;
				break;
			}
		}
	}
	ans += 1LL;
	printf("%lld\n", ans);
	return 0;
}
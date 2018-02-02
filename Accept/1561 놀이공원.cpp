#include<stdio.h>
int n, m, arr[10000];
int chk(long long c) {
	long long cnt = m;
	for (int i = 0; i < m; i++)
		cnt += (c / arr[i]);
	return cnt >= n;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);
	long long low = 0LL, high = 2000000000LL * 10000LL, minute, ans=0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (chk(mid)) {
			high = mid - 1;
			minute = mid;
		}
		else {
			low = mid + 1;
		}
	}
	if (minute > 0) {
		ans = m;
		for (int i = 0; i < m; i++) {
			ans += ((minute - 1) / arr[i]);
		}
		for (int i = 0; i < m; i++) {
			if (minute % arr[i] == 0) {
				ans++;
			}
			if (ans == n) {
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}
	else {
		printf("%d\n", n);
	}	
	return 0;
}
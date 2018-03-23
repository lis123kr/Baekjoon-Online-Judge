#include<stdio.h>
int n, m;
long long arr[100000];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	long long low = 0, high = 1e18, mid=0;
	while (low <= high) {
		mid = (high - low) / 2 + low;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += mid / arr[i];
		}
		if (sum >= m) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	printf("%lld\n", high + 1);
	return 0;
}
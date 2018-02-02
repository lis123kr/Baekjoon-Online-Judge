#include<stdio.h>
typedef long long LL;
int arr[500001], b[500001];

LL merge(int p, int q) {
	LL ans=0;
	int mid = (p + q) / 2;
	int i = p, j = mid + 1, idx = 0;
	while (i <= mid && j <= q) {
		if (arr[i] <= arr[j]) b[idx++] = arr[i++];
		else { ans += (long long)mid - i + 1; b[idx++] = arr[j++]; }
	}
	while (i <= mid) b[idx++] = arr[i++];
	while (j <= q) b[idx++] = arr[j++];
	for (int i = p; i <= q; i++) {
		arr[i] = b[i - p];
	}
	return ans;
}
LL solve(int p, int q) {
	if (p == q) return 0;
	else {
		int mid = (p + q) / 2;
		LL ans = solve(p, mid) + solve(mid + 1, q);
		ans += merge(p, q);
		return ans;
	}	
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%lld\n", solve(0, n - 1));
	return 0;
}
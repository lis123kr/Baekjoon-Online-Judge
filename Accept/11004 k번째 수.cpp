#include<stdio.h>
#include<algorithm>
int n, arr[5000001], k;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::stable_sort(arr, arr + n);
	printf("%d", arr[k - 1]);
	return 0;
}
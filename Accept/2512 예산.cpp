#include<stdio.h>
int n, arr[10001], c, ans;
int inline min(int a, int b) { return (a) > (b) ? (b) : (a); }
int cmp(int nc) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(arr[i], nc);
	}
	return sum <= c;
}
int main() {
	int sum = 0, h=0;
	scanf("%d", &n);	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		if (h < arr[i]) 
			h = arr[i];
	}
	scanf("%d", &c);
	int left = 1, right = 100000;
	if (sum > c) {
		while (left <= right) {
			int mid = (left + right) / 2;
			if (cmp(mid)) {
				left = mid + 1;
				ans = mid;
			}
			else {
				right = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
	else {
		printf("%d\n", h);
	}
	
	return 0;
}
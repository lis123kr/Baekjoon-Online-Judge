#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
long long arr[1000000];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	long long pre = arr[0], cnt = 0, re, mm=-1;
	for (i = 0; i < n; i++) {
		if (pre != arr[i]) {
			if (cnt > mm) {
				mm = cnt;
				re = arr[i-1];
			}
			cnt = 1;
			pre = arr[i];
		}
		else {
			cnt++;
		}
	}
	if (cnt > mm) {
		mm = cnt;
		re = arr[i - 1];
	}
	printf("%lld", re);
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long arr[3];
long long dp[3];
int n;
int main() {
	freopen("input.txt", "r", stdin);
	int t = 1;
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		scanf("%lld %lld %lld", arr, arr + 1, arr + 2);
		arr[0] = 99999999;
		arr[2] += arr[1];
		for (int i = 1; i < n; i++) {
			scanf("%lld %lld %lld", dp, dp + 1, dp + 2);
			dp[0] += min(arr[0], arr[1]);
			dp[1] += min(min(arr[0], dp[0]), min(arr[1], arr[2]));
			dp[2] += min(min(arr[1], dp[1]), arr[2]);
			arr[0] = dp[0];
			arr[1] = dp[1];
			arr[2] = dp[2];
		}
		printf("%d. %lld\n", t++, arr[1]);
	}
	return 0;
}
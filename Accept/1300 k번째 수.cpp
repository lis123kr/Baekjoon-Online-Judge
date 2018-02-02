#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
	int left = 1, right = 1e9;
	int ans = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(n, mid / i);
		}
		if (cnt>=k) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
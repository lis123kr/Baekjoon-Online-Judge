#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, c;
vector<int> arr;
bool possible(int dist) {
	int cnt = 1;
	int last = arr[0];
	for (int x : arr) {
		if (x - last >= dist) {
			cnt++;
			last = x;
		}
	}
	return cnt >= c;
}
int main() {
	scanf("%d %d", &n, &c);
	arr = vector<int>(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int low = 1, high = arr[n-1] - arr[0];
	int ans = 1;
	while (low <= high) {
		int center = (low + high) / 2;
		if (possible(center)) {
			if (ans < center)
				ans = center;
			low = center + 1;
		}
		else
			high = center - 1;
	}
	printf("%d\n", ans);
	return 0;
}
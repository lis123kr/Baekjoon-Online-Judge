#include<stdio.h>
#include<algorithm>
using namespace std;
int n, arr[500001];
double sum;
pair<int, int>cnt[8001];
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		cnt[arr[i] + 4000].first++;
		cnt[arr[i] + 4000].second = arr[i] + 4000;
	}
	sort(arr, arr + n);
	sort(cnt, cnt + 8001, cmp);
	printf("%0.lf\n%d\n%d\n%d\n", sum / n, arr[n / 2], cnt[8000].first == cnt[7999].first ? cnt[7999].second-4000 : cnt[8000].second-4000, arr[n - 1] - arr[0]);
	return 0;
}
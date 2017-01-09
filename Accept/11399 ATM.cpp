#include<cstdio>
#include<algorithm>
using namespace std;
int n;
pair<int, int> arr[1001];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n, cmp);
	int sum = 0;
	for (int i = 0; i < n-1; i++)
		arr[i + 1].first += arr[i].first;
	for (int i = 0; i < n; i++)
		sum += arr[i].first;
	printf("%d", sum);
	return 0;
}
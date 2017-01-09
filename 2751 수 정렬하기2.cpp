#include<cstdio>
#include<algorithm>
int n, arr[1000001];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::sort(arr + 0, arr + n);
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
	return 0;
}
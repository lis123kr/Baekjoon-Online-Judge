#include <cstdio>
int n;
int arr[502][502];
int cache[502][502]; //501 -> Æ²¸²
int max(int a, int b) { return a > b ? a : b; }
int dp(int i, int j) {
	int &cur = arr[i][j], h = 0;
	int &ret = cache[i][j];
	if (ret != 0) return ret;
	if (cur >= arr[i - 1][j] && cur >= arr[i + 1][j] && cur >= arr[i][j - 1] && cur >= arr[i][j + 1])
		return ret = 1;
	if (cur < arr[i + 1][j])
		h = max(h, 1 + dp(i + 1, j));
	if (cur < arr[i - 1][j])
		h = max(h, 1 + dp(i - 1, j));
	if (cur < arr[i][j - 1])
		h = max(h, 1 + dp(i, j - 1));
	if (cur < arr[i][j + 1])
		h = max(h, 1 + dp(i, j + 1));

	return ret = h;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	int h = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			h = max(h, dp(i, j));
	printf("%d\n", h);
	return 0;
}
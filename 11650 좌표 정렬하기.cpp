#include<cstdio>
#include<algorithm>
int n;
struct point {
	int x;
	int y;
};
bool cmp(const struct point& a, const struct point& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
struct point arr[100001];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int a, b;

	for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
	std::sort(arr + 0, arr + n, cmp);
	for (int i = 0; i < n; i++) printf("%d %d\n", arr[i].x, arr[i].y);
	return 0;
}
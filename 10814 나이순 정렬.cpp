#include<cstdio>
#include<algorithm>
int n;
struct name {
	int a;
	char Name[101];
};
struct name arr[100001];
bool cmp(const struct name& a, const struct name& b) {
	return a.a < b.a;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);	
	for (int i = 0; i < n; i++) scanf("%d %s", &arr[i].a, arr[i].Name);
	std::stable_sort(arr + 0, arr + n, cmp);
	for (int i = 0; i < n; i++) printf("%d %s\n", arr[i].a, arr[i].Name);
	return 0;
}
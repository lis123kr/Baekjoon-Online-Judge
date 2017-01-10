#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
struct stu {
	char name[101];
	int g, y, s;
};
struct stu arr[100001];
bool cmp(const struct stu& a, const struct stu& b) {
	if (a.g == b.g) {
		if (a.y == b.y) {
			if (a.s == b.s) return strcmp(a.name, b.name)==-1;
			return a.s > b.s;
		}
		return a.y < b.y;
	}
	return a.g > b.g;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s %d %d %d", arr[i].name, &arr[i].g, &arr[i].y, &arr[i].s);
	stable_sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) printf("%s\n", arr[i].name);
	return 0;
}
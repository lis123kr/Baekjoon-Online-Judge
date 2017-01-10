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

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct S {
	char name[11], lang, eng, math;
};
bool nameCmp(S x, S y) {
	if (strcmp(x.name, y.name) < 0) return true;
	else return false;
}
bool langCmp(S x, S y) {
	return x.lang > y.lang;
}
bool engCmp(S x, S y) {
	return x.eng < y.eng;
}
bool mathCmp(S x, S y) {
	return x.math > y.math;
}
vector<S> v;
int main() {
	S s;
	//char n[11], l, e, m;
	int n; scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%s %hhd %hhd %hhd", s.name, &s.lang, &s.eng, &s.math);
		v.push_back(s);
	}
	stable_sort(v.begin(), v.end(), nameCmp);
	stable_sort(v.begin(), v.end(), mathCmp);
	stable_sort(v.begin(), v.end(), engCmp);
	stable_sort(v.begin(), v.end(), langCmp);
	for (int i = 0; i<n; i++) {
		printf("%s\n", v[i].name);
	}
	return 0;
}
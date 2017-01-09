#include<cstdio>
#include<cstring>
char arr[1001];
int n, cache[1001][10001];
int pal(int p, int q) {
	if (p>=q) return 1;
	if ( q < n && arr[p] != arr[q]) return -1;
	int &ret = cache[p][q];
	if (ret != 0) return ret;
	return ret = pal(p + 1, q - 1);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%s", arr);
	n = strlen(arr);
	int q = n - 1;
	while (pal(0, q++) == -1);
	printf("%d", q);
	return 0;
}
#include<stdio.h>
#include<string.h>
int n, w, m[1010][2], cache[1010][1010];
int inline max(int a, int b) { return a > b ? a : b; }
int inline min(int a, int b) { return a < b ? a : b; }
int inline abs(int a) { return a > 0 ? a : -a; }
int dist(int a, int b) {
	return abs(m[a][0] - m[b][0]) + abs(m[a][1] - m[b][1]);
}
int solve(int a, int b) {
	int next = 1 + max(a, b);
	if (next == w + 2)
		return 0;
	int &ret = cache[a][b];
	if (ret != -1)
		return ret;
	int da = dist(a, next);
	int db = dist(b, next);
	return ret = min(da + solve(next, b), db + solve(a, next));
}
void path(int a, int b) {
	int next = 1 + max(a, b);
	if (next == w + 2)
		return;
	int da = dist(a, next), db = dist(b, next);
	if (da + solve(next, b) > db + solve(a, next)) {
		printf("2\n");
		path(a, next);
	}
	else {
		printf("1\n");
		path(next, b);
	}
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &w);
	m[0][0] = m[0][1] = 1;
	m[1][0] = m[1][1] = n;
	for (int i = 2; i < w + 2; i++)
		scanf("%d %d", &m[i][0], &m[i][1]);
	printf("%d\n", solve(0, 1));
	path(0, 1);
	return 0;
}
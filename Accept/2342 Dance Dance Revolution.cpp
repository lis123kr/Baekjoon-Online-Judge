#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001],cache[100001][5][5];
int distance(int &d) {
	if (d == 0) d = 1;
	else if (d == 1 || d == 3) d = 3;
	else d = 4;
}
int dp(int p, int left, int right) {
	if (a[p] == 0) return 0;
	int &ret = cache[p][left][right];
	if (ret != 0) return ret;

	int d1 = abs(a[p] - left), d2 = abs(a[p] - right);
	distance(d1); distance(d2);
	if (left == 0)d1 = 2;
	if (right == 0)d2 = 2;

	return ret = min(dp(p + 1, a[p], right)+d1, dp(p + 1, left, a[p])+d2);
}
int main() {
	freopen("input.txt", "r", stdin);
	int result=0;
	for (int i = 0;; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) break;			
	}
	printf("%d", dp(0,0,0));
	return 0;
}
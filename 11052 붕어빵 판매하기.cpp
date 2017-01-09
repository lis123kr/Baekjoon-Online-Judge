#include <cstdio>
#include<algorithm>
using namespace std;
int n, p[1001];
int cache[1001];
int dp(int i) {
	if (i <= 0) return 0;
	int &ret = cache[i];
	if (ret != 0) return ret;
	int h = 0;
	for (int j = 1; j <= n; j++) {
		if(i-j>=0)
			h = max(h, dp(i - j) + p[j]);
	}
	return ret = h;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	printf("%d\n", dp(n));
	return 0;
}
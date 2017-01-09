#include<cstdio>
int arr[5001], n=0;
int cache[5001][27];
int dp(int p, int num) {
	if (p > n || num == 0 || num > 26) return 0;
	if (p == n) return 1;
	int &ret = cache[p][num];
	if (ret != 0) return ret;
	if (arr[p] != 0) // Accepted when this line is inserted
		return ret = (dp(p + 1, arr[p]) % 1000000 + dp(p + 2, arr[p] * 10 + arr[p + 1]) % 1000000) % 1000000;
	else
		return 0;
}
int main() {
	freopen("input.txt", "r", stdin);	
	while (scanf("%1d", &arr[n++]) == 1); n--;
	arr[0] == 0 ? printf("0") : printf("%d", dp(0, 1) % 1000000);
	return 0;
}
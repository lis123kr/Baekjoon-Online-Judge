#include<stdio.h>
int n, k, check[26];
char str[51][16];
int inline max(int a, int b) { return a > b ? a : b; }
int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 4; str[i][j]; j++) {
			if (!check[str[i][j] - 'a']) {
				flag = 0;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	return cnt;
}
int solve(int p, int cnt) {
	if (cnt == 0) {
		return count();
	}
	int ret = 0;
	for (int alp = p; alp < 26; alp++) {
		if (!check[alp]) {
			check[alp] = 1;
			ret = max(ret, solve(alp+1,cnt - 1));
			check[alp] = 0;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	if (k < 5) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < 5; i++)
		check["acnti"[i] - 'a'] = 1;
	k -= 5;
	for (int i = 0; i < n; i++)
		scanf(" %s", str[i]);
	printf("%d\n",solve(0,k));
	return 0;
}
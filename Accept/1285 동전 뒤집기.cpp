#include<stdio.h>
char arr[21][21];
int n;
char flip(char a) { return a == 'H' ? 'T' : 'H'; }
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf(" %c", &arr[i][j]);
	int ans = n*n;
	for (int s = 0; s < (1 << n); s++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				char cur = arr[i][j];
				if (s & (1 << j)) {
					cur = flip(cur);
				}
				if (cur == 'T') cnt++;
			}
			sum += cnt < n - cnt ? cnt : n - cnt;
		}
		if (ans > sum) ans = sum;
	}
	printf("%d\n", ans);
	return 0;
}
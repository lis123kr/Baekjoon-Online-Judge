#include<stdio.h>
#include<string.h>
int t, n, k, d[111][111][2];
int main() {
	scanf("%d", &t);
	d[2][0][1] = d[2][1][1] = 1;
	d[2][0][0] = 2;
	for (int i = 3; i <= 100; i++) {
		for (int j = 0; j < i; j++) {
			d[i][j][0] = d[i - 1][j][0] + d[i - 1][j][1];
			d[i][j][1] = d[i - 1][j][0] + d[i - 1][j - 1][1];
		}
	}
	while (t--) {		
		scanf("%d %d", &n, &k);
		printf("%d\n", d[n][k][0] + d[n][k][1]);
	}
	return 0;
}
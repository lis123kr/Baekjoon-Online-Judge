#include<stdio.h>
int a, b, c, m, n, arr[701][701], col[701], ci;
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		ci = m - 1;
		scanf("%d %d %d", &a, &b, &c);
		while (c > 0 && ci >= 0) {
			col[ci--] += 2;
			c--;
		}			
		while (b > 0 && ci >= 0) {
			col[ci--] += 1;
			b--;
		}
		ci = 1;
		while (c-- > 0) 
			arr[ci++][0] += 2;
		while (b-- > 0)
			arr[ci++][0] += 1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {			
			printf("%d ", 1 + arr[i][j] + ((i==0 || j!=0) ? col[j] : 0));			
		}
		printf("\n");
	}
	return 0;
}
#include<stdio.h>
#include<math.h>
#define SIZE  15501
int n, m, arr[31], d[2][SIZE];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (d[0][j]) {
				d[1][abs(j - arr[i])] = d[1][arr[i] + j] = 1;
			}
		}
		d[1][arr[i]] = 1;
		for (int j = 0; j < SIZE; j++)
			d[0][j] = d[1][j];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &n);
		printf("%c ", d[0][n] == 0 ? 'N' : 'Y');
	}
	printf("\n");
	return 0;
}
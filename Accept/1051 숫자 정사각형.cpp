#include<stdio.h>

int arr[55][55], n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);
	int p = n > m ? m : n;
	p--;
	for (int q = p; q >= 0; q--) {
		for (int i = 1; i + q <= n; i++) {
			for (int j = 1; j + q <= m; j++) {
				if (arr[i][j] == arr[i + q][j] &&
					arr[i + q][j] == arr[i + q][j + q] &&
					arr[i + q][j + q] == arr[i][j + q]) {
					q++;
					printf("%d\n", q*q);
					return 0;
				}
			}
		}
	}
	return 0;
}
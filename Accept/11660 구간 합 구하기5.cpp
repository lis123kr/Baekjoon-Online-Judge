#include<stdio.h>
int n, m, arr[1111][1111];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
		for (int j = 1; j <= n; j++) {
			arr[i][j] += arr[i - 1][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int ans = 0, x1,x2,y1,y2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);		
		printf("%d\n", arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1]);
	}	
	return 0;
}
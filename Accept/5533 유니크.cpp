#include<stdio.h>
int n,arr[201][3], ans[201];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
	}
	for (int j = 0; j < 3; j++) {
		for (int i = 1; i <= n; i++) {
			bool chk = true;
			for (int p = 1; p <= n; p++) {
				if (i == p)continue;
				if (arr[i][j] == arr[p][j]) {
					chk = false;
					break;
				}
			}
			if (chk)
				ans[i] += arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
#include<cstdio>

//ans: n-lis
int n, arr[300], num[300];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++) {
		int max = 0;
		num[i] = 1;
		for (int j = i - 1; j > 0; j--) {
			if (arr[j] < arr[i]) {
				max = max > num[j] ? max : num[j];
				num[i] = max + 1;
			}
		}
	}
	int max = 0;
	for(int i = 1; i <= n; i++) if (max < num[i]) max = num[i];
	printf("%d\n", n - max);
	return 0;
}
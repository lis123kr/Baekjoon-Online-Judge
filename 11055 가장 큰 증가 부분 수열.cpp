#include<cstdio>
int n, arr[1001], re[1001];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {	
		re[i] = arr[i];
		int max = 0;
		for (int j = i - 1; j > 0; j--) {
			if (arr[j] < arr[i]) {
				max = max > re[j] ? max : re[j];
				re[i] = max + arr[i];
			}			
		}
	}
	int max = re[1];
	for (int i = 1; i <= n; i++) if (max < re[i]) max = re[i];
	printf("%d\n", max);
	return 0;
}
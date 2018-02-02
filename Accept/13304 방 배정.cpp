#include<stdio.h>
int main() {
	int n, k, s, y, arr[2][3] = { 0 }, ans=0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &y);
		if (y <= 2)
			arr[0][0]++;
		else if (y <= 4)
			arr[s][1]++;
		else
			arr[s][2]++;
	}
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 1; j++) {
			if (arr[j][i] > 0) {
				ans += (arr[j][i] / k);
				if (arr[j][i] % k != 0)
					ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include<stdio.h>
int n, han[1001] = { 0,1,1,1,1,1,1,1,1,1,1 },ans;
int main() {
	for (int i = 11; i <= 1000; i++) {
		int flag = 0, d=11, cor=1;
		for (int j = 1000; j >= 1; j /= 10) {
			if (flag) {
				if (d != 11 && d != i / (j*10) %10 - i/j%10) {
					cor = 0;
					break;
				}
				else {
					d = i / (j * 10) % 10 - i / j % 10;
				}
			}
			if (i / j % 10 != 0) {
				flag = 1;
			}
		}
		if (cor) {
			han[i] = 1;
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		if (han[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}
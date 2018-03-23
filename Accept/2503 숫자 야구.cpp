#include<stdio.h>
int n, num[100], s[100], b[100], ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &num[i], &s[i], &b[i]);
	for (int i = 0; i < 1000; i++) {
		int flag = 1;
		int i1 = i / 100;
		int i2 = i / 10 % 10;
		int i3 = i % 10;
		if (i1 == i2 || i2 == i3 || i1 == i3 || i1==0 || i2==0 || i3==0) 
			continue;
		for (int j = 0; j < n; j++) {
			int ss = 0, bb = 0;
			int n1 = num[j] / 100;
			int n2 = num[j] / 10 % 10;
			int n3 = num[j] % 10;
			if (i1 == n1) ss++;
			else if (i1 == n2 || i1 == n3) bb++;
			if (i2 == n2) ss++;
			else if (i2 == n1 || i2 == n3) bb++;
			if (i3 == n3) ss++;
			else if (i3 == n1 || i3 == n2) bb++;

			if (ss != s[j] || bb != b[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
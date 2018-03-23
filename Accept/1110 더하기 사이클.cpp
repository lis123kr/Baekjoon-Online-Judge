#include<stdio.h>
int ori, n, cnt;
int main() {
	scanf("%d", &n);
	ori = n;
	do {
		cnt++;
		int pre = n % 10;
		int next = ((n / 10) + (n % 10)) % 10;
		n = pre * 10 + next;
	} while (ori != n);
	printf("%d\n", cnt);
	return 0;
}
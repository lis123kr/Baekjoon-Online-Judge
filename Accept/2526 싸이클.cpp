#include<stdio.h>
int n, nn, p, chk[1001], cnt=1;
int main() {
	scanf("%d %d", &n, &p);
	nn = n;
	chk[n] = cnt++;
	while (chk[n * nn % p] == 0) {
		n = n*nn%p;		
		chk[n] = cnt++;
	}
	printf("%d\n", cnt- chk[n*nn%p]);
	return 0;
}
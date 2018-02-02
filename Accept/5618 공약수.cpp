#include<stdio.h>
int GCD(int a, int b) {
	if (b > a) return GCD(b, a);
	if (b == 0) return a;
	else return GCD(a%b, b);
}
int main() {
	int n,a[3], gcd;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	gcd = a[0];
	for (int i = 1; i < n; i++) {
		gcd = GCD(gcd, a[i]);
	}
	for (int i = 1; i <= gcd; i++) {
		if(gcd%i==0)
			printf("%d\n", i);
	}	
	return 0;
}
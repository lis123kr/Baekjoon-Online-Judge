//3
#include<stdio.h>
int n;
int main() {
	scanf("%d", &n);
	int g[7] = { 0,1,0,1,2,3,2 };
	printf("%s\n", g[n % 7] == 0 ? "CY" : "SK");
	return 0;
}
//4
#include<stdio.h>
int n;
int main() {
	scanf("%d", &n);
	int g[8] = { 1,0,1,0,1,1,1 };
	printf("%s\n", g[n % 7] == 0 ? "CY" : "SK");
	return 0;
}

//6
#include<stdio.h>
long long n;
int main() {
	scanf("%lld", &n);
	int g[7] = { 0,1,0,1,2,3,2 };
	printf("%s\n", g[n % 7LL] == 0 ? "CY" : "SK");
	return 0;
}
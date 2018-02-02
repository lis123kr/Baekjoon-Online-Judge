#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0)
		printf("CY\n");
	else
		printf("SK\n");	
	return 0;
}

//2
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 != 0)
		printf("CY\n");
	else
		printf("SK\n");
	return 0;
}

//5
#include<stdio.h>
int main() {
	long long n;
	scanf("%lld", &n);
	if (n % 2LL == 0)
		printf("CY\n");
	else
		printf("SK\n");
	return 0;
}

//7
#include<stdio.h>
long long n;
int main() {
	scanf("%lld", &n);
	int arr[5] = { 0,1,0,1,1 };
	printf("%s\n", arr[n % 5LL] == 0 ? "CY" : "SK");
	return 0;
}
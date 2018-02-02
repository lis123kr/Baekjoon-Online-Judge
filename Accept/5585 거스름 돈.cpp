#include<stdio.h>
int n;
int main() {
	scanf("%d", &n);
	n = 1000 - n;
	int arr[6] = { 500,100,50,10,5,1 };
	int cnt = 0,i=0;
	while (n > 0) {
		cnt += n / arr[i];
		n %= arr[i];
		i++;
	}
	printf("%d", cnt);
	return 0;
}
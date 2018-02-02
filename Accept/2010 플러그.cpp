#include<stdio.h>
int n;
long long sum=1;
int main() {
	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		sum += (tmp - 1);
	}
	printf("%lld\n", sum);
	return 0;
}
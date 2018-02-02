#include<stdio.h>
int n, num[31], count, arr[31], p;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (num[i] == 0) {
			printf("-1");
			return 0;
		}
	}
	arr[0] = p = num[0]; count++;
	printf("%d\n", n);	
	while (count < n) {
		p %= n;
		while (arr[p] != 0) {
			p = (p + 1) % n;
		}
		arr[p] = num[count];
		p = (p + num[count]) % n;
		count++;
	}
	for(int i=0;i<n;i++)
		printf("%d ", arr[i]);
	return 0;
}
#include <stdio.h>

int gcd(int a, int b){
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int t, n;
	int a[100] = { 0 };
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		int a[101] = { 0 };
		for (int j = 0; j < n; j++)
			scanf("%d", &a[j]);
		int sum = 0;
		for (int j = 0; j < n - 1; j++)	{
			for (int k = j + 1; k < n; k++)	{
				sum += gcd(a[j], a[k]);
			}
		}
		printf("%d\n", sum);
	}
}
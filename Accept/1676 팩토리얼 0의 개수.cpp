#include<stdio.h>
#include<math.h>
int arr[511],n;
int main() {
	int p = 0;	// 2x5가 되는 개수를 세면 된다...
				// 2는 충분... 5의 개수만 세면되는듯
	for (int i = 5; i <= 500; i++) {
		if (i % 5 == 0)
			p++;
		if (i % 25 == 0)
			p++;
		if (i % 125 == 0)
			p++;
		arr[i] = p;
	}
	scanf("%d", &n);
	printf("%d\n", arr[n]);
	return 0;
}
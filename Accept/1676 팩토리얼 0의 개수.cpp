#include<stdio.h>
#include<math.h>
int arr[511],n;
int main() {
	int p = 0;	// 2x5�� �Ǵ� ������ ���� �ȴ�...
				// 2�� ���... 5�� ������ ����Ǵµ�
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
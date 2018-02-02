//10707
#include<stdio.h>
int main() {
	int A, B, C, D, P;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
	int ans = A*P;
	printf("%d\n", C >= P ? (ans > B ? B : ans) : (ans > B + (P - C)*D ? (B + (P - C)*D) : ans));
	return 0;
}

//10718
#include<stdio.h>
int main() {
	printf("강한친구 대한육군\n강한친구 대한육군\n");
	return 0;
}

//10797
#include<stdio.h>
int main() {
	int n, arr[5],cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		scanf("%d", arr + i);
		if (n == arr[i]) cnt++;
	}	
	printf("%d\n", cnt);
	return 0;
}
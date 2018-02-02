#include<stdio.h>
int A[1000000], B[1000000], ans[2000000];
int main() {
	int a, b, ai=0,bi=0,ni=0;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < b; i++)
		scanf("%d", &B[i]);

	while (ai<a || bi<b){
		if (ai < a && (bi >= b || A[ai] <= B[bi])) {
			ans[ni++] = A[ai++];
		}
		else {
			ans[ni++] = B[bi++];
		}
	}
	for (int i = 0; i < a + b; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
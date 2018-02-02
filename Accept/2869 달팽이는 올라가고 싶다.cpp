#include<stdio.h>
#include<math.h>
int A, B, V;
int main() {
	scanf("%d %d %d", &A, &B, &V);
	V -= A;
	int ans = (int)ceil((double)V / (A - B));
	printf("%d", ans + 1);
	return 0;
}
#include<stdio.h>
#include<algorithm>
using namespace std;
int A[101], B[101];
bool cmp(int a, int b) {
	if (a > b) return true;
	else return false;
}
int main() {
	int sum = 0, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", A + i);
	for (int i = 0; i < n; i++) scanf("%d", B + i);
	sort(A, A + n);
	sort(B, B + n, cmp);
	for (int i = 0; i < n; i++) sum += A[i] * B[i];
	printf("%d", sum);
	return 0;
}
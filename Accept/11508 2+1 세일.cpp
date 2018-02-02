#include<stdio.h>
#include<algorithm>
using namespace std;
int n, A[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, A + n);
	int t = 1;
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--, t++) {
		if (t % 3 != 0)
			ans += (long long)A[i];
	}
	printf("%lld\n", ans);
	return 0;
}
#include<stdio.h>
#include<math.h>
typedef unsigned long long ull;
ull A, B, C;
ull mul(ull a, ull b) {
	if (b == 0) return 1;
	if (b % 2 == 1) return a*mul(a, b - 1) % C;
	else {
		ull half = mul(a, b / 2) % C;
		return (half* half) % C;
	}
}
int main() {
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld\n", mul(A, B) % C);
	return 0;
}
#include <iostream>

using namespace std;
//d(p) = d(p-1) + d(p-2)
int main() {
	int n;
	cin >> n;
	int fibo_0 = 1, fibo_1 = 1,sum;
	for (int i = 2; i <= n; i++) {
		sum = (fibo_0 + fibo_1) % 10007;
		fibo_0 = fibo_1;
		fibo_1 = sum;
	}
	printf("%d\n", fibo_1);
	return 0;
}
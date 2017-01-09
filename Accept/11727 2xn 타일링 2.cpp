#include<iostream>

using namespace std;

int main() {
	int n,fibo_0=1,fibo_1=1,tmp;
	cin >> n;
	for (int i = 1; i < n; i++) {
		tmp = (fibo_0*2 + fibo_1) % 10007;
		fibo_0 = fibo_1;
		fibo_1 = tmp;
	}
	cout << fibo_1 << endl;
	return 0;
}
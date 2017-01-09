#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int result = 0;
	int a=1, b=0, c;
	for (int i = 0; i <= n; i++) {
		c = (a + b) % 9901;
		b = c + a;
		a = c;
		
	}
	cout << a << endl;
	return 0;
}
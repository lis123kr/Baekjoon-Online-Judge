#include<iostream>
//조금 더 이해 필요
//dp(n) = 3*dp(n-2) + for i=0~ i+=2 : 2 *dp(n-2-i)
 using namespace std;
int n;
int d[50];
int main() {
	cin >> n;
	d[0] = 1;
	d[2] = 3;
	if (n % 2 == 0) {
		for (int i = 4; i <= n; i += 2) {
			d[i] = 3 * d[i - 2];
			for (int j = 4; j <= i; j += 2) {
				d[i] += 2 * d[i - j];
			}
		}
		cout << d[n] << endl;
	}
	else cout << 0 << endl;
	return 0;
}
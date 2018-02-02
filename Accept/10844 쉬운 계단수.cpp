#include <iostream>
using namespace std;
int n;
int cache[101][10];
int dp(int i,int j) {
	if (j < 0 || j>9) return 0;
	int &ret = cache[i][j];
	if (i == n) return 1;
	if (ret != 0) return ret;
	return ret = (dp(i + 1, j - 1) + dp(i + 1, j + 1)) % 1000000000;
}
int main() {
	cin >> n;
	int result = 0;
	for (int i = 1; i <= 9; i++) {
		result += dp(1, i) % 1000000000;
		result %= 1000000000; // point!
	}
	cout << result % 1000000000 << endl;
	return 0;
}
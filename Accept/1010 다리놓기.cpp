#include<iostream>
#include<algorithm>
using namespace std;
int DP[31][31];
int dp(int p, int q) {
	if (q == 0 || p == q || p==0) return 1;
	int &ret = DP[p][q];
	if (ret != 0)return ret;
	return ret=dp(p - 1, q - 1) + dp(p - 1, q);
}

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << dp(b,a) << endl;
	}
	return 0;
}
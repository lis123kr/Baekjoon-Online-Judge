#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long S[11], B[11], ans = 1e9;
int n;
void solve(int p, long long s, long long b, bool isfood) {
	if (p == n) {
		if(isfood)
			ans = min(ans, abs(s - b));
		return;
	}
	else {
		solve(p + 1, s, b, isfood);
		solve(p + 1, s * S[p], b + B[p], true);
	}
}
int main() {	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> S[i] >> B[i];
	solve(0, 1, 0, false);
	cout << ans << endl;
	return 0;
}
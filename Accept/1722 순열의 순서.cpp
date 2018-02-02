#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long f[21] = { 1 };
bool c[21];
int main() {
	int n, k;
	for (int i = 1; i <= 20; i++) f[i] = f[i - 1] * i;
	cin >> n >> k;
	vector<int>v(n);
	if (k == 1) {
		long long kk;
		cin >> kk;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[j]) continue;
				if (f[n - i - 1] < kk) kk -= f[n - i - 1];
				else {
					v[i] = j;
					c[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
	}
	else {		
		for (int i = 0; i < n; i++) cin >> v[i];
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) {
				if (!c[j]) ans += f[n - i - 1];
			}
			c[v[i]] = true;
		}
		cout << ans+1;
	}
	cout << "\n";
	return 0;
}
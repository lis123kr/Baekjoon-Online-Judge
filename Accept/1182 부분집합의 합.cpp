#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n, s, cnt=0;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i <= (1 << n) - 1; i++) {
		int sum = 0; bool chk = false;
		for (int b = 0; b < n; b++) {
			if (i & (1 << b)) {
				sum += v[b];
				chk = true;
			}
		}
		if (sum == s && chk) 
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
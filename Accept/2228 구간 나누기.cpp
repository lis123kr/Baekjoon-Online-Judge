#include<iostream>
#include<algorithm>
#define	MIN	-99999999
using namespace std;
int n, m, arr[101], S[101], ans;
int cache[101][101];
bool chk[101][101];
// p개의 수를 q개의 그룹으로 나눌때, 구간 합의 최대값
int dp(int p, int q) {
	if (q == 0) return 0;
	if (p <= 0) return MIN;
	if (chk[p][q]) return cache[p][q];
	chk[p][q] = true;
	int &ret = cache[p][q];
	ret = dp(p - 1, q);
	for (int i = p; i >=1; i--) {
		ret = max(ret, dp(i - 2, q - 1) + S[p] - S[i - 1]);
	}
	return ret;
}
int main() {	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		S[i] = S[i - 1] + arr[i];
	}
	cout << dp(n, m) << endl;
	return 0;
}
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n, k, dp[33][33][33][500];
string ans;
int go(string s, int p, int a, int b, int cur) {
	if (cur > k) return 0;
	if (p == n){
		if (cur == k) {
			ans = s;
			return 1;
		}
		return 0;
	}
	if (dp[p][a][b][cur] != -1) return dp[p][a][b][cur];
	return dp[p][a][b][cur] = go(s + "A", p + 1, a + 1, b, cur) || 
		go(s + "B", p + 1, a, b + 1, cur + a) || go(s + "C", p + 1, a, b, cur + a + b);
}
int main() {
	cin >> n >> k;
	string str = "";
	memset(dp, -1, sizeof(dp));
	go(str, 0, 0, 0, 0);
	cout << ((ans=="") ? "-1":ans) << endl;
	return 0;
}
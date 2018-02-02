#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string str, ans;
int dp[4][4][51][51][51];
int solve(string s, char pp, char p,int a,int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	if (a == 0 && b == 0 && c == 0) {
		ans = s;
		return 1;
	}
	int &ret = dp[pp - 'A'][p - 'A'][a][b][c];
	if (ret != -1) return ret;
	if (pp != 'C' && p != 'C') ret = solve(s + 'C', p, 'C', a, b, c - 1);
	if (p != 'B') ret = solve(s + 'B', p, 'B', a, b - 1, c);
	ret = solve(s + 'A', p, 'A', a - 1, b, c);
	return ret;
}
int main() {	
	cin >> str;
	int a=0, b=0, c=0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A')
			a += 1;
		else if (str[i] == 'B')
			b += 1;
		else
			c += 1;
	}
	string s = "";
	solve(s, 'A', 'A', a, b, c);
	if(ans.length()!=0)
		cout << ans << endl;
	else
		cout << "-1" << endl;
	return 0;
}
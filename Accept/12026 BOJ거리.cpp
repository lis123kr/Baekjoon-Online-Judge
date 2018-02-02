#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, dp[1001];
string str;
char *boj = "BOJ";
char next_jump(char a) {
	int t;
	if (a == 'B') t = 0;
	else if (a == 'O') t = 1;
	else t = 2;
	return boj[(t + 1) % 3];
}
int main() {
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		dp[i] = 1e9;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		char nt = next_jump(str[i]);
		for (int k = i + 1; k < n; k++) {
			if (str[k] == nt) {
				dp[k] = min(dp[k], dp[i] + (k - i)*(k - i));
			}
		}	
	}
	cout << ((dp[n - 1] == 1e9) ? -1 : dp[n - 1]) << endl;
	return 0;
}

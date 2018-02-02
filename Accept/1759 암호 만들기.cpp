#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool check(string str) {
	int ja = 0, mo = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
			str[i] == 'o' || str[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}
	return (mo >= 1 && ja >= 2);
}
void go(int n, vector<char>& alpha, string pass, int pos) {
	if (n == pass.length()) {
		if (check(pass)) {
			cout << pass << '\n';
		}
		return;
	}
	if (pos >= alpha.size()) return;
	go(n, alpha, pass + alpha[pos], pos + 1);
	go(n, alpha, pass, pos + 1);
}

int main() {
	int L, C;
	scanf("%d %d", &L, &C);
	vector<char>alpha(C);
	for (int i = 0; i < C; i++) cin >> alpha[i];
	sort(alpha.begin(), alpha.end());
	go(L, alpha, "", 0);

	
	return 0;
}
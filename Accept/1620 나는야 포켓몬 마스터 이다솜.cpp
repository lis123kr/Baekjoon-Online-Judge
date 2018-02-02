#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<string.h>
using namespace std;
int n, m;
map<string, int> M;
string p[100001],s;
int stoi(string str) {
	int ans = 0;
	for (int i = 0; i < str.length() ; i++) {
		ans *= 10;
		ans += str[i] - '0';
	}
	return ans;
}
int main() {
	char buffer[22];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buffer);
		p[i] = (string)buffer;
		M.insert(make_pair(p[i], i + 1));
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", buffer);
		s = (string)buffer;
		if ('0' <= s[0] && s[0] <= '9')
			printf("%s\n", p[stoi(s)- 1].c_str());
		else
			printf("%d\n", M[s]);
	}
	return 0;
}
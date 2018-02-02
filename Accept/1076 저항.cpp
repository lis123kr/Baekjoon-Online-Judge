#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
long long ans;
int sw(string s) {
	if (s == "black") return 0;
	else if (s == "brown") return 1;
	else if (s == "red") return 2;
	else if (s == "orange") return 3;
	else if (s == "yellow") return 4;
	else if (s == "green") return 5;
	else if (s == "blue") return 6;
	else if (s == "violet") return 7;
	else if (s == "grey") return 8;
	else if (s == "white") return 9;
}
int main() {
	string s;
	cin >> s;
	ans = sw(s) * 10;
	cin >> s;
	ans += sw(s);
	cin >> s;
	ans *= (long long)pow(10, (double)sw(s));
	cout << ans << endl;
	return 0;
}
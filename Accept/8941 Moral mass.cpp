#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		char ch = NULL;
		double ans = 0;
		for (int i = 0; i < str.length(); i++) {
			bool letter = false;
			int n = 1;
			if (str[i] == 'C' || str[i] == 'H' || str[i] == 'O' || str[i] == 'N') letter = true;
			if (letter) {
				ch = str[i];
				if (i + 1 < str.length() && (str[i + 1] >= '0' && str[i + 1] <= '9')) continue;
			}
			else {
				if (str[i + 1] >= '0' && str[i + 1] <= '9') {
					n = stoi(str.substr(i, 2));
					i++;
				}
				else {
					n = str[i] - '0';
				}
			}
			switch (ch) {
			case 'C':
				ans += 12.01 * n;
				break;
			case 'H':
				ans += 1.008 * n;
				break;
			case 'O':
				ans += 16.0 * n;
				break;
			case 'N':
				ans += 14.01 *n;
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
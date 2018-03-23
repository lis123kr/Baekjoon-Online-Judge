#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string A, B;
int inline min(int a, int b) { return a > b ? b : a; }
int main() {
	cin >> A >> B;
	int blen = B.length(), alen = A.length();
	int ans = 1e9;
	for (int i = 0; i <= blen-alen; i++) {
		int cnt = 0;
		for (int p = 0; p < alen; p++) {
			if (B[i + p] != A[p])
				cnt++;
		}
		ans = min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
struct STACK {
	char x[1000001];
	char w[40];
	int wlen, top;
	STACK(string c4) {
		memset(x, 0, sizeof(x));
		memset(w, 0, sizeof(w));
		top = 0;
		strcpy(w, c4.c_str());
		wlen = strlen(w);
		reverse(w, w + wlen);
	}
	void push(char c) {
		x[top++] = c;
	}

	void chk() {
		if (top - wlen < 0) return;
		for (int i = 0; i < wlen; i++) {
			if (x[top - 1 - i] != w[i]) return;
		}
		top -= wlen;
	}
};

int main() {
	string str, c4;
	cin >> str >> c4;
	STACK s(c4);
	char last = c4.back();
	for (int i = 0; i < str.length(); i++) {
		s.push(str[i]);
		if (last == str[i]) {
			s.chk();
		}
	}
	if (s.top == 0) {
		cout << "FRULA" << endl;
	}
	else {
		for (int i = 0; i < s.top; i++) {
			cout << s.x[i];
		}
	}
	return 0;
}
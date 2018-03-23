#include<stdio.h>
#include<iostream>
#include<string>
#include<list>
using namespace std;
int t, flag;
int main() {
	scanf("%d", &t);	
	while (t--) {
		flag = 0;
		string s;
		cin >> s;
		std::list<char> L;
		list<char>::iterator it = L.begin();
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {
				if (it != L.begin())
					it--;
			}
			else if (s[i] == '>') {
				if (it != L.end())
					it++;
			}
			else if (s[i] == '-') {
				if (!L.empty()) {
					if (it == L.end()) {
						L.pop_back();
						it = L.end();
					}
					else if (it == L.begin()) {
						continue;
					}
					else {
						it--;
						it = L.erase(it);
					}
				}
			}
			else {
				if (it == L.end()) {
					L.push_back(s[i]);
					it = L.end();
				}
				else {
					it = L.insert(it, s[i]);
					if (it != L.end())
						it++;
				}
			}
		}
		for (; L.size();) {
			printf("%c", L.front());
			L.pop_front();
		}
		printf("\n");
	}
	return 0;
}

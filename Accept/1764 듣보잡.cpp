#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	set<string>s,s2;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		if(s.find(str)!=s.end())
			s2.insert(str);
	}
	cout << s2.size() << '\n';
	for (auto it = s2.begin(); it != s2.end(); it++)
		cout << *it << '\n';

	return 0;
}
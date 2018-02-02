#include<iostream>
#include<string>
#include<set>
using namespace std;
int main() {
	int n;
	cin >> n;
	string person, log;
	set<string> s;
	for (int i = 0; i < n; i++) {
		cin >> person >> log;
		if (log == "enter") s.insert(person);
		else if (log == "leave") s.erase(person);
	}
	
	for (auto it = s.crbegin(); it != s.crend(); it++)
		cout << *it << '\n';
	return 0;
}
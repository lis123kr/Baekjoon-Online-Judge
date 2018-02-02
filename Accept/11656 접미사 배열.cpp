#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
struct SuffixComparator {
	const string &s;
	SuffixComparator(const string &s) : s(s) {}
	bool operator()(const int i, const int j) {
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
	}
};
vector<int> getSuffixArr(const string s) {
	vector<int> p;
	for (int i = 0; i < s.size(); i++) p.push_back(i);
	sort(p.begin(), p.end(), SuffixComparator(s));
	return p;
}
int main() {
	freopen("input.txt", "r", stdin);
	string s;
	cin >> s;
	vector<int> re = getSuffixArr(s);
	for (int i = 0; i < s.size(); i++) {
		printf("%s\n", s.c_str() + re[i]);
	}
	return 0;
}
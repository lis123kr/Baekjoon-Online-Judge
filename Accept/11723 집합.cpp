#include<iostream>
#include<stdio.h>
#include<set>
#include<string.h>
using namespace std;
int n, v;
char op[20];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	set <int> s, p = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	
	for (int i = 0; i < n; i++) {
		scanf("%s %d", op, &v);

		if (strcmp(op, "add") == 0) {
			s.insert(v);
		}
		else if (strcmp(op, "remove") == 0) {
			if(s.find(v) != s.end()) s.erase(v);
		}
		else if (strcmp(op, "check") == 0) {
			if (s.find(v) == s.end()) printf("0\n");
			else printf("1\n");
		}
		else if (strcmp(op, "toggle") == 0) {
			if (s.find(v) == s.end()) s.insert(v);
			else s.erase(s.find(v));
		}
		else if (strcmp(op, "all") == 0) {
			s = p;
		}
		else if (strcmp(op, "empty") == 0) {
			s.clear();
		}

	}
	return 0;
}
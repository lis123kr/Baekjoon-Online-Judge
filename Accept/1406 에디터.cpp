#include<stdio.h>
#include<cstring>
#include<list>
using namespace std;
int n;
list<char> L;
char str[100001];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%s", str);
	L = list<char>(str, str + strlen(str));
	auto it = L.end();
	scanf("%d", &n); char a;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &a);
		if (a == 'P') {
			scanf(" %c", &a);
			L.insert(it, a);
		}
		else if (a == 'L') {
			if (it != L.begin()) it--;
		}
		else if (a == 'D') {
			if (it != L.end()) it++;
		}
		else {
			if (it != L.begin()) {
				auto tmp = it;
				L.erase(--tmp);
			}
		}
	}
	while (!L.empty()) {
		printf("%c", L.front());
		L.pop_front();
	}
	return 0;
}
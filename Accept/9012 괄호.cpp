#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
int t;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		vector<char>v;
		char tmp[55] = { 0 };
		scanf("%s", tmp);
		int leng = strlen(tmp);
		for (int i = 0; i < leng; i++) {
			if (tmp[i] == ')') {
				if (v.empty()) { v.push_back(tmp[i]); break; }
				if (!v.empty() && v.back() == '(') v.pop_back();
				else break;
			}
			else v.push_back(tmp[i]);
		}
		if (v.empty()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
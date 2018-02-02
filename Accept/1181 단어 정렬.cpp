#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
struct word {
	char str[51];
};
bool cmp(const struct word& a, const struct word& b) {
	if (strlen(a.str) == strlen(b.str)) return strcmp(a.str, b.str) < 0;
	else if (strlen(a.str) < strlen(b.str)) return true;
	else return false;
}
struct word str[20002] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);	
	for (int i = 0; i < n; i++) scanf("%s", str[i].str);
	sort(str, str + n, cmp);
	for (int i = 0; i < n; i++) {
		if (strcmp(str[i].str, str[i + 1].str) == 0) continue; 
		printf("%s\n", str[i].str);
	}
	return 0;
}
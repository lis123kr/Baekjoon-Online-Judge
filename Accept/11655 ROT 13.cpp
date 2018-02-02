#include<stdio.h>
#include<string.h>
#include<string>
int main() {
	freopen("input.txt", "r", stdin);
	char str[111];
	gets_s(str);
	int leng = strlen(str);
	for (int i = 0; i < leng; i++) {
		if (str[i] == ' ') continue;
		if (isupper(str[i])) {
			int a = str[i] + 13;
			if (a > 'Z') str[i] = a - 'Z' + 'A'-1;
			else str[i] = a;
		}
		else if (islower(str[i])) {
			int a = str[i] + 13;
			if (a > 'z') str[i] = a - 'z' + 'a'-1;
			else str[i] = a;
		}		
	}
	for (int i = 0; i < leng; i++) printf("%c", str[i]);
	return 0;
}
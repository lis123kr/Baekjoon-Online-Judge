#include<stdio.h>
#include<string.h>
int n, arr[30];
char str[111];
int main() {
	scanf("%s", str);
	int leng = strlen(str);
	for (int i = 0; i < leng; i++)
		arr[str[i] - 'a']++;
	for (int i = 0; i < 26; i++) printf("%d ", arr[i]);
	return 0;
}
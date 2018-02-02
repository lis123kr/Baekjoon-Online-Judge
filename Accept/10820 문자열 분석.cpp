#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
char str[111];
int arr[4];
int main() {
	freopen("input.txt", "r", stdin);
	while (cin.getline(str, 101)) {
		int leng = strlen(str);
		for (int i = 0; i < leng; i++) {
			if (str[i] == ' ') arr[3]++;
			else if ('0' <= str[i] && str[i] <= '9') arr[2]++;
			else if (isupper(str[i])) arr[1]++;
			else arr[0]++;
		}
		for (int i = 0; i < 4; i++) printf("%d ", arr[i]);
		printf("\n");
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}
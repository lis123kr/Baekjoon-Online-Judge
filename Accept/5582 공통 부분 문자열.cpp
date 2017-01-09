#include<cstdio>
#include<algorithm>
#include<cstring>
char str1[4001], str2[4001];
int arr[4001][4001],m;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%s %s", str1, str2);
	int leng1 = strlen(str1), leng2 = strlen(str2);
	for (int i = 1; i <= leng1; i++) {
		for (int j = 1; j <= leng2; j++) {
			if (str1[i - 1] == str2[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = 0;
			m = std::max(m, arr[i][j]);
		}
	}
	printf("%d", m);
	return 0;
}
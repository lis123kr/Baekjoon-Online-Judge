#include<stdio.h>
#include<algorithm>
#include<string.h>
char ans[100001];
int main() {
	int sum=0, a;
	bool check = false;
	scanf("%s", ans);
	int len = strlen(ans);
	for (int i = 0; i < len; i++) {
		sum += ans[i] - '0';
		if (ans[i] == '0') check = true;
	}
	if (check && sum % 3 == 0) {
		std::sort(ans, ans + len);
		std::reverse(ans, ans + len);
		printf("%s\n", ans);
	}
	else {
		printf("-1\n");
	}
	return 0;
}
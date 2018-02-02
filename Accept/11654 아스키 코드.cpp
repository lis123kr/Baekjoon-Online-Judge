// 11654 아스키 코드
#include<stdio.h>
int main() {
	char a;
	scanf("%c", &a);
	printf("%d", a);
	return 0;
}


// 11718
#include<stdio.h>
#include<string.h>
int main() {
	freopen("input.txt", "r", stdin);
	char buf[101] = { 0 };
	while (true) {
		fflush(stdin);
		gets_s(buf, 101);
		if (buf[0] == 0) break;
		printf("%s\n", buf);
		memset(buf, 0, sizeof(buf));
	}
	return 0;
}
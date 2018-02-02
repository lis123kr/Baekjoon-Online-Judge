#include<stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	char c;
	bool minus = false;
	int num = 0, ans=0;
	while (scanf(" %c", &c) == 1) { // scanf 공백 중요
		if (c == '+' || c=='-') {
			if (minus) {
				ans -= num;
			}
			else ans += num;
			num = 0;
			if (c == '-') minus = true;
		}
		else {
			num = num * 10 + (c - '0');
		}
	}
	if(minus) ans -= num;
	else ans += num;
	printf("%d\n", ans);
	return 0;
}
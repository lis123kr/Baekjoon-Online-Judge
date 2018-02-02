#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);
	int a, b, c, y=1;
	a = b = c = 1;
	while (a != e || b != s || c != m) {
		y++;
		a++, b++, c++;
		if (a == 16)a = 1;
		if (b == 29)b = 1;
		if (c == 20)c = 1;
	}
	printf("%d\n", y);
	return 0;
}
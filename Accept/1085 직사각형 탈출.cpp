#include<stdio.h>
int x, y, w, h;
int inline min(int a, int b) { return a > b ? b : a; }
int inline abs(int a) { return a > 0 ? a : -a; }
int main() {
	scanf("%d%d%d%d", &x, &y, &w, &h);
	printf("%d\n", min(min(abs(x - 0), abs(y - 0)), min(abs(x - w), abs(y - h))));
	return 0;
}
#include<stdio.h>
#include<algorithm>
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	if (n == 1) printf("1\n");
	else if (n == 2) printf("%d\n",std::min(4, (m + 1) / 2));
	else {
		if (m >= 7) printf("%d\n", m - 2);
		else printf("%d\n", std::min(4, m));
	}
	return 0;
}
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	int x1, x2, y1, y2;
	x1 = x2 = y1 = y2 = n / 2;
	if (n % 2 == 0) y2 = x2 = n / 2 + 1;
	int center = (n+1) / 2;
	// 2 = ÆÄ¶û, 1 = »¡°­, 0 = ³ë¶û
	for (int i = 0; i < k; i++) {
		int color = center % 3;
		int a, b;
		scanf("%d %d", &a, &b);
		if (n % 2 == 1) {
			a = abs(a - center);
			b = abs(b - center);
		}
		else {
			if (a > center) a -= center;
			else a = center + 1 - a;

			if (b > center) b -= center;
			else b = center + 1 - b;
		}

		int c = max(a, b) % 3;
		if (n % 2 == 0) {
			if (c == 2) color -= 1;
			else if (c == 0) color -= 2;
		}
		else {
			if (c == 1) color -= 1;
			else if (c == 2) color -= 2;
		}

		if (color == -1) color = 2;
		else if (color == -2) color = 1;

		printf("%d\n", color == 0 ? 3 : color);
	}

	return 0;
}
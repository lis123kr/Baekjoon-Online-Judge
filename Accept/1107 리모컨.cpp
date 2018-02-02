#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, arr[10];
int possible(int c) {
	if (c == 0) return arr[c] == 1 ? 0 : 1;
	else {
		int len = 0;
		while (c > 0) {
			if (arr[c % 10]==1) return 0;
			c /= 10;
			len++;
		}
		return len;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int a;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		arr[a] = 1;	// ºÎ¼ÅÁü
	}
	int ans = abs(100-n);
	for (int i = 0; i <= 1000000; i++) {
		int len = possible(i);
		if (len>0) {
			int press = abs(i - n);
			if (ans > len + press)
				ans = len + press;
		}
	}
	printf("%d\n", ans);
	return 0;
}
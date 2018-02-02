#include<stdio.h>
int n;
int chk(int leng, int arr[]) {
	if (leng == 0) return 1;
	else if (leng == 1) return arr[0] != arr[1];
	for (int i = leng - 1; i >= 0; i-=2) {
		int s = 1;
		int p = i + (leng + 1 - i) / 2;
		for (int j = 0; j < p-i; j++) {
			if (arr[i + j] != arr[p + j]) {
				s = 0;
				break;
			}
		}
		if (s)
			return 0;
	}
	return 1;
}
int solve(int p, int arr[]) {
	if (p == n) {
		for (int i = 0; i < p; i++)
			printf("%d", arr[i]);
		return 1;
	}
	for (int i = 1; i <= 3; i++) {
		arr[p] = i;
		if (chk(p, arr)) {
			if(solve(p + 1, arr))
				return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	int arr[100] = { 0 };
	solve(0, arr);
	printf("\n");
	return 0;
}
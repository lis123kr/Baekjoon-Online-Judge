#include<cstdio>
#include<cstring>
int n;
void add_arr(int arr[], int b[]) {
	int carry = 0,idx=0;
	for (int i = 0; i < 500; i++) {
		arr[i] += b[i] + carry;
		carry = arr[i] / 10;
		arr[i] %= 10;
	}
}
void mul_arr(int arr[], int b) {
	int carry = 0;
	for (int i = 0; i < 500; i++) {
		arr[i] = arr[i] * b + carry;
		carry = arr[i] / 10;
		arr[i] %= 10;
	}
}
int main() {
	freopen("input.txt", "r", stdin);	
	while (scanf("%d", &n) == 1) {
		int arr[501] = { 3 },i;
		int tmp0[501] = { 1,1,3 }, tmp1[501] = { 1 };
		if (n < 3) { printf("%d\n", tmp0[n]); continue; }
		for (i = 3; i <= n; i++) {
			memcpy(tmp0, arr, sizeof(tmp1));
			mul_arr(tmp1, 2);
			add_arr(arr, tmp1);
			memcpy(tmp1, tmp0, sizeof(tmp1));
		}
		for (i = 500; i >= 0; i--) if (arr[i] != 0) break;
		for (int j = i; j >=0; j--) printf("%d", arr[j]);
		printf("\n");
	}
	return 0;
}
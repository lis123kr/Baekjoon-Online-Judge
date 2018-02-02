#include<stdio.h>
#include<algorithm>
using namespace std;
int maxdiff(int n,int arr[]) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		cnt += abs(arr[i] - arr[i - 1]);
	}
	return cnt;
}
int main() {
	int n, arr[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", arr + i);
	sort(arr, arr + n);
	int ans = 0;
	do {
		int tmp = maxdiff(n, arr);
		ans = ans > tmp ? ans : tmp;
	} while (next_permutation(arr, arr + n));
	printf("%d\n", ans);
	return 0;
}
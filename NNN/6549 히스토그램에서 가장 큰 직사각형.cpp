//#include<cstdio>
//#define	INF	99999999
//int n;
//int arr[100001], left[100001], right[100001];
//int main() {
//	freopen("input.txt", "r", stdin);
//	while (true) {
//		
//		scanf("%d", &n);
//		if (n == 0) break;
//		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
//		for (int i = 1; i <= n; i++) { left[i] = 1; right[i] = INF; }
//		int i, index=1;
//		for (i = 1; i <= n; i++) {
//			if (arr[i] > arr[i + 1]) {
//				right[i] = i + 1;
//			}
//			if (arr[i] < arr[i + 1]) {
//				left[i + 1] = i + 1;
//			}
//		}
//		index = i; arr[index] = 0;
//		for (int j = n; j > 0; j--) {
//			if (right[j] == INF) right[j] = index;
//			if (arr[j] > arr[index]) index = j+1;
//		}
//
//		for (int i = 1; i <= n; i++) { printf("%d %d\n", left[i], right[i]); }
//	}
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n;
	int arr[15][15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf("%d", &arr[i][j]);

	int TSP[14] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int ans = 999999999;
	do {
		int sum = 0;
		bool ok = true;
		for (int i = 1; i < n; i++) {
			sum += arr[ TSP[i - 1] ][ TSP[i] ];
			if (arr[TSP[i - 1]][TSP[i]] == 0) ok = false;
		}
		if (ok && 0 != arr[TSP[n - 1]][TSP[0]])
			if(ans > sum + arr[TSP[n - 1]][TSP[0]])
				ans = sum + arr[TSP[n - 1]][TSP[0]];
	} while (next_permutation(TSP, TSP + n)); // TSP +1, TSP+n  ==> n! 시간복잡도, 현재는 n*n!
	printf("%d\n", ans);
	return 0;
}
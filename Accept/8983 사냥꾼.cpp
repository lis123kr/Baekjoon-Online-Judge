#include<stdio.h>
#include<vector>
#include<algorithm>
int M, N, L, m[100001], ans;
int main() {
	scanf("%d %d %d", &M, &N, &L);
	for (int i = 0; i < M; i++)
		scanf("%d", &m[i]);
	std::sort(m + 0, m + M);	
	for (int i = 0; i < N; i++) {
		int low = 0, high = M - 1, x, y, mid;
		scanf("%d %d", &x, &y);
		while (low <= high) {
			mid = (low + high) / 2;
			if (m[mid] == x) {
				break;
			}
			else if (m[mid] < x) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		if (std::abs(x - m[mid]) + y <= L || (mid <M && std::abs(x-m[mid+1]) + y <= L ||
			(mid > 0 && std::abs(x-m[mid-1]) + y <= L)))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
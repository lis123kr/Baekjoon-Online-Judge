#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int main() {
	freopen("input.txt", "r", stdin);
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 || m == 0) break;
		vector< vector<int> >b = vector< vector<int> >(n+5);
		int tmp, rowmax[111111] = { 0 };
		for (int i = 0; i < n; i++) {
			b[i] = vector<int>(m+5);
			for (int j = 0; j < m; j++) {
				scanf("%d", &tmp);
				b[i][j] = tmp;
			}
		}
		for (int i = 0; i < n; i++) {
			b[i][2] += b[i][0];
			rowmax[i] = max(b[i][1],b[i][2]);
			for (int j = 3; j < m; j++) {
				b[i][j] += max(b[i][j - 2] , b[i][j - 3]);
				rowmax[i] = max(rowmax[i], b[i][j]);
			}
		}	
		rowmax[2] += rowmax[0];
		tmp = max(rowmax[1], rowmax[2]);
		for (int i = 3; i < n; i++) {
			rowmax[i] += max(rowmax[i - 2], rowmax[i - 3]);
			tmp = max(tmp, rowmax[i]);
		}
		printf("%d\n", tmp);
		memset(rowmax, 0, sizeof(rowmax));
		b.clear();
	}
	return 0;
}
//#include<stdio.h>
//#include<vector>
//int inline min(int a, int b) { return a > b ? b : a; }
//int n, m, dist[101][101], path[101][101];
//int main() {
//	const int INF = 1e9;
//	int a, b, c;
//	for (int i = 0; i <= 100; i++) {
//		for (int j = 0; j <= 100; j++) {
//			dist[i][j] = INF;
//		}
//	}
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < m; i++) {
//		scanf("%d %d %d", &a, &b, &c);
//		if (dist[a][b] > c) {
//			dist[a][b] = c;
//			path[a][b] = a;
//		}		
//	}
//	for (int i = 0; i <= 100; i++)
//		dist[i][i] = 0;
//	for (int k = 1; k <= n; k++) {
//		for (int i = 1; i <= n; i++) {
//			if (i == k) continue;
//			for (int j = 1; j <= n; j++) {
//				if (i == j) continue;
//				if (dist[i][j] > dist[i][k] + dist[k][j]) {
//					dist[i][j] = dist[i][k] + dist[k][j];
//					path[i][j] = k;
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]);
//		}
//		printf("\n");
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (i == j) { printf("0\n"); continue; }
//			std::vector<int> v, f;
//			int x = path[i][j], cnt=2;			
//			int xx = x;
//			if (i != x) {
//				while (xx != i) {
//					cnt++;
//					f.push_back(xx);
//					xx = path[i][xx];
//				}				
//				while (path[x][j] != x) {
//					x = path[x][j];
//					v.push_back(x);
//					cnt++;
//				}
//			}
//			printf("%d ", cnt);
//			f.push_back(i);
//			for (int p = f.size()-1; p >=0; p--)
//				printf("%d ", f[p]);
//			for (int p = 0; p < v.size(); p++)
//				printf("%d ", v[p]);
//			printf("%d\n", j);
//		}
//		
//	}
//	return 0;
//}

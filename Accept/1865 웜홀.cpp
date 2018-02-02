// �� ������ �����ϴ� �ٸ��� 2���̻��� �� �ִ�.
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
	int from, to, cost;
};
int dist[501];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		vector<Edge>v(2 * m + w);
		for (int i = 1; i <= n; i++) dist[i] = 1e9;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &v[i].from, &v[i].to, &v[i].cost);
			v[i + m] = v[i];
			swap(v[i + m].from, v[i + m].to);
		}
		for (int i = 2*m; i < 2*m+w; i++) {
			scanf("%d %d %d", &v[i].from, &v[i].to, &v[i].cost);
			v[i].cost *= -1;
		}
		bool ans = false;
		dist[1] = 0;
		for (int i = 1; i <= n; i++) { // n-1 ��
			for (int j = 0; j <m*2+w; j++) { // �� ��忡 ����
				int x = v[j].from;
				int y = v[j].to;
				int c = v[j].cost;
				if (dist[x] != 1e9 && dist[y] > dist[x] + c) {
					dist[y] = dist[x] + c;
					if (i == n) ans = true;
				}
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, cost[10001], a[10001], ind[10001];
vector<int>v[10001];
int main() {
	scanf("%d", &n);
	int c, j;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &j);
		for (int p = 0; p < j; p++) {
			scanf("%d", &c);
			ind[i] += 1;
			v[c].push_back(i);
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			cost[i] = a[i];
		}
	}
	// 선행작업이 없을 수도 있다!!!
	// 무조건 k를 하려면 1~k-1을 완료해야하므로 반복문으로 해야함...
	//while (!q.empty()) {
	//	int cur = q.front();
	//	q.pop();
	//	for (int i = 0; i < v[cur].size(); i++) {
	//		int next = v[cur][i];
	//		ind[next] -= 1;
	//		if (cost[next] < cost[cur] + a[next])
	//			cost[next] = cost[cur] + a[next];
	//		if (ind[next] == 0) {
	//			q.push(next);
	//		}
	//	}
	//}
	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		for (int j = 0; j < v[cur].size(); j++) {
			int next = v[cur][j];
			ind[next] -= 1;
			if (ind[next] == 0) {
				q.push(next);
			}
			if (cost[next] < cost[cur] + a[next])
				cost[next] = cost[cur] + a[next];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < cost[i])
			ans = cost[i];
	}
	printf("%d\n", ans);
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int tt[1001], ind[1001], cost[1001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, a, b, w;
		memset(tt, 0, sizeof(tt));
		memset(ind, 0, sizeof(ind));
		memset(cost, 0, sizeof(cost));
		vector<int> v[1001];
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &tt[i]);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			ind[b] += 1;
		}
		queue<int>q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				q.push(i);
				cost[i] = tt[i];
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];
				ind[next] -= 1;
				if (cost[next] < cost[cur] + tt[next]) 
					cost[next] = cost[cur] + tt[next];
				if (ind[next] == 0) 
					q.push(next);
			}
		}
		scanf("%d", &w);
		printf("%d\n", cost[w]);
	}
	return 0;
}
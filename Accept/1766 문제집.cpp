#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, ind[40000];
vector<int>v[40000];
int main() {
	int a, b;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		ind[b] += 1;
	}
	priority_queue<int>pq;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			pq.push(-i);
		}
	}
	while (!pq.empty()) {
		int cur = -pq.top();
		printf("%d ", cur);
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			ind[next] -= 1;
			if (ind[next] == 0) {
				pq.push(-next);
			}
		}
	}
	printf("\n");
	return 0;
}
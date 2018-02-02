#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
vector<int> v[40000];
int ind[40000];
int main() {
	scanf("%d %d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		ind[b] += 1;
	}
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			ind[next] -= 1;
			if (ind[next] == 0) q.push(next);
		}
	}
	printf("\n");
	return 0;
}
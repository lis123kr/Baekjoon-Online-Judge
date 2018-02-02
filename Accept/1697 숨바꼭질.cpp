#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int n, k;
bool visited[100001];
int main() {
	scanf("%d %d", &n, &k);
	queue< int > q;
	vector<int>dist(100001);
	q.push(n);
	dist[n] = 0;
	visited[n] = true;
	int next[3] = { -1,1,n };
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		next[2] = cur;
		for (int i = 0; i < 3; i++) {
			int d = cur + next[i];
			if (d >= 0 && d <= 100000) {
				if (!visited[d]) {
					q.push(d);
					visited[d] = true;
					dist[d] = dist[cur] + 1;
				}
			}			
		}
	}
	printf("%d\n", dist[k]);
	return 0;
}
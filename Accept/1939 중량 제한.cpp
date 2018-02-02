#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
bool solve(vector< vector< pair<int, int> > >& v, int src, int dst, int dist) {
	int memoi = 0;
	queue< pair<int, int> > q;
	vector< bool >visited(n + 1);
	q.push(make_pair(src, dist));
	while (!q.empty()) {
		int cur = q.front().first;
		int weight = q.front().second;
		visited[cur] = true;
		q.pop();
		if (cur == dst) return true;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nw = v[cur][i].second;
			if (!visited[next] && nw >= dist) {
				q.push(make_pair(next, nw));
			}
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &n, &m);
	int a, b, c, low = 1, high = 1;
	vector< vector< pair<int, int> > > v(n + 1);
	
	for (int i = 0; i<m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
		if (high < c) high = c;
	}
	int src, dst;
	scanf("%d %d", &src, &dst);
	int ans = 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (solve(v, src, dst, mid)) {
			low = mid + 1;
			if (mid > ans) ans = mid;
		}
		else
			high = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
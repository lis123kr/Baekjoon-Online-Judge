#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
bool cmp(const std::pair<int,int> &a, const std::pair<int,int> &b) {
	return a.first < b.first;
}
int n, m;
std::vector < std::vector<int> > g(20001);
bool visited[20001];
int main() {
	int a, b, big=0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	std::queue< std::pair<int,int> >q;
	std::vector< std::pair<int,int> > ans;
	q.push(std::make_pair(0,1));
	visited[1] = true;
	while (!q.empty()) {
		auto np = q.front(); q.pop();
		if (np.second != 1) {
			ans.push_back(np);
			if (np.first > big)
				big = np.first;
		}
		for (int i = 0; i < g[np.second].size(); i++) {
			if (!visited[g[np.second][i]]) {
				q.push(std::make_pair(np.first + 1, g[np.second][i]));
				visited[g[np.second][i]] = true;
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	auto lower = std::lower_bound(ans.begin(), ans.end(), std::make_pair(big, 0), cmp) - ans.begin();
	auto upper = std::upper_bound(ans.begin(), ans.end(), std::make_pair(big, 0), cmp) - ans.begin();
	printf("%d %d %d\n", ans[lower].second, ans[lower].first, upper-lower);
	return 0;
}
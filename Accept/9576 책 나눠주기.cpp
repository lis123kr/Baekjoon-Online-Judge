#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
bool cmp(const pair<int, int>& p, const pair<int, int>& q) {
	if (p.second != q.second)
		return p.second < q.second;
	return p.first < q.first;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector< pair<int, int> > v(m);
		vector< bool > chk(n + 1, false);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &v[i].first, &v[i].second);
		sort(v.begin(), v.end(), cmp);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for(int j=v[i].first; j<= v[i].second; j++){
				if (!chk[j]) {
					chk[j] = true;
					ans++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

// TL
//
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//struct MF {
//	struct Edge {
//		int to, c;
//		struct Edge *rev;
//		Edge(int to, int c) :to(to), c(c) {};
//	};
//	int n, src, sink;
//	vector< vector< Edge * > > graph;
//	vector< bool > chk;
//	MF(int n, int src, int sink) : n(n), src(src), sink(sink) {
//		graph.resize(n);
//		chk.resize(n);
//	}
//	void addEdge(int u, int v, int c) {
//		Edge *e1 = new Edge(v, c);
//		Edge *e2 = new Edge(u, 0);
//		e1->rev = e2;
//		e2->rev = e1;
//		graph[u].push_back(e1);
//		graph[v].push_back(e2);
//	}
//	int dfs(int x, int c) {
//		if (chk[x])
//			return 0;
//		chk[x] = true;
//		if (sink == x)
//			return c;
//		for (int i = 0; i < graph[x].size(); i++) {
//			if (graph[x][i]->c > 0) {
//				int nc = graph[x][i]->c;
//				if (c != 0 && nc > c) {
//					nc = c;
//				}
//				int f = dfs(graph[x][i]->to, nc);
//				if (f) {
//					graph[x][i]->c -= f;
//					graph[x][i]->rev->c += f;
//					return f;
//				}
//			}
//		}
//		return 0;
//	}
//	int flow() {
//		int ans = 0;
//		while (true) {
//			fill(chk.begin(), chk.end(), 0);
//			int f = dfs(src, 0);
//			if (f == 0)
//				break;
//			ans += f;
//		}
//		return ans;
//	}
//};
//int main() {
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		int a,b,n, m;
//		scanf("%d %d", &n, &m);
//		MF mf(n + m + 2, 0, n + m + 1);
//		for (int i = 1; i <= n; i++)
//			mf.addEdge(0, i, 1);
//		for (int i = n + 1; i <= n + m; i++) {
//			scanf("%d %d", &a, &b);
//			for (int j = a; j <= b; j++) {
//				mf.addEdge(j, i, 1);
//			}
//			mf.addEdge(i, n + m + 1, 1);
//		}
//		printf("%d\n", mf.flow());
//	}
//	return 0;
//}
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct edge {
	int from;
	int to;
	int cost;
	edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};
const long long INF = 1LL << 60;

vector<edge> Edge;
long long D[100];
int R[100][100];
int Money[100];


int main() {

	int N, Start, End, M;

	scanf("%d %d %d %d", &N, &Start, &End, &M);
	//	Edge = vector<vector<edge>>(M + 1);
	memset(R, 0, sizeof(R));

	for (int i = 1; i <= M; i++) {
		int x, y, z;

		scanf("%d %d %d", &x, &y, &z);
		Edge.push_back(edge(x, y, z));
		R[x][y] = 1;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &Money[i]);
		R[i][i] = 1;
	}

	fill(D, D + N, INF);

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (R[i][k] && R[k][j]) R[i][j] = 1;

	D[Start] = -Money[Start];

	int Gee = 0; int gg = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int node = Edge[j].from;
			int next = Edge[j].to;
			int next_cost = Edge[j].cost;
			if (D[node] != INF && D[next] > D[node] + next_cost - Money[next]) {
				D[next] = D[node] + next_cost - Money[next];
				if (i == N - 1 && R[next][End] == 1) Gee = 1;
			}
		}
	}

	if (D[End] == INF)  gg = 1;
	if (Gee == 1) puts("Gee");
	else if (gg == 1) puts("gg");
	else printf("%lld\n", -D[End]);

	return 0;
}
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int INF = 999999999;
//int main() {
//	int n, src, dst, m, a, b, c;
//	long long arr[100];
//	scanf("%d %d %d %d", &n, &src, &dst, &m);
//	vector< vector< pair<int, long long> > > v(n + 1);
//	vector<long long>dist(n + 1, INF);
//	dist[src] = 0;
//	for (int i = 0; i < m; i++) {
//		scanf("%d %d %d", &a, &b, &c);
//		if (a == b)
//			c = 0;
//		v[a].push_back(make_pair(b, c));
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//		for (int j = 0; j < v[i].size(); j++) {
//			v[i][j].second -= arr[i];
//		}
//	}
//	bool chk = false;
//	if (n > 1) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				for (int p = 0; p < v[j].size(); p++) {
//					if (dist[v[j][p].first] > dist[j] + v[j][p].second) {
//						dist[v[j][p].first] = dist[j] + v[j][p].second;
//						if (i == n - 1)
//							chk = true;
//					}
//				}
//			}
//		}
//		if (chk)
//			cout << "Gee\n";
//		else if (dist[dst] == INF)
//			cout << "gg\n"; 
//		else
//			cout << arr[dst] - dist[dst] << endl;
//	}
//	else {
//		cout << arr[0] << endl;
//	}
//	return 0;
//}
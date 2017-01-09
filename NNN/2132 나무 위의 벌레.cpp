//#include<cstdio>
//#include<algorithm>
//#include<stdlib.h>
//#include<queue>
//#include<cstring>
//#include<vector>
//using namespace std;
//vector<int>f;
//vector<int>starts;
//bool visited[10001];
//unsigned int longest;
//int start;
//int n;
////5
////1 2 3 4 5
////1 2
////2 3
////3 4
////3 5
//void bfs(const vector< vector< pair<int, unsigned int> > > &Tree, int num) {
//	memset(visited, 0, sizeof(visited));
//	queue< pair <int, unsigned int> > q;
//	visited[num] = true;
//	q.push(make_pair(num, f[num])); // f[num] -> 0
//	starts.push_back(num);
//
//	while (!q.empty()) {
//		unsigned int next = q.front().first, weight = q.front().second;
//		q.pop();
//		if (weight > longest) {
//			longest = weight;
//			starts.push_back(next);
//			start = next;
//		}
//		for (int i = 0; i < Tree[next].size(); i++) {
//			if (!visited[Tree[next][i].first]) {
//				q.push(make_pair(Tree[next][i].first, Tree[next][i].second + weight));
//				visited[Tree[next][i].first] = true;
//			}
//		}
//	}
//}
//
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	vector< vector< pair<int, unsigned int> > >Tree(n + 1);
//	f = vector<int>(n + 1);
//	int a, b;
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a);
//		f[i] = a;
//	}
//
//	for (int i = 1; i < n; i++) {
//		scanf("%d %d", &a, &b);
//		Tree[a].push_back(make_pair(b, f[b]));
//		Tree[b].push_back(make_pair(a, f[a]));
//	}
//
//	bfs(Tree, 1);
//	int startn = start;
//	longest = 0;
//	starts.clear();
//	bfs(Tree, start);
//
//	//for (int i = 0; i < starts.size(); i++) {
//	//	longest -= f[starts[i]];
//	//}
//	printf("%d %d\n", longest/* + f[startn] + f[start]*/, min(startn, start));
//	return 0;
//}
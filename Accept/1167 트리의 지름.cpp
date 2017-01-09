#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n;
vector< vector< pair<int, int> > >arr;
bool visited[100001];
int startv, maxw=0;
void BFS(int v) {
	visited[v] = true;
	queue< pair<int, int> > q;
	q.push(make_pair(v, 0));
	while (!q.empty()) {
		int next = q.front().first, weight = q.front().second;
		q.pop();
		if (maxw < weight) {
			startv = next;
			maxw = weight;
		}
		for (int i = 0; i < arr[next].size(); i++) {
			if (!visited[arr[next][i].first]) {
				visited[arr[next][i].first] = true;
				q.push(make_pair(arr[next][i].first, weight+arr[next][i].second));
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	arr = vector< vector< pair<int, int> > >(n + 1);
	int a, b, j;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		j = a;
		while (scanf("%d", &a) == 1) { 
			if (a == -1) break;
			scanf("%d", &b);
			arr[j].push_back(make_pair(a, b)); 
			arr[a].push_back(make_pair(j, b));
		}
	}
	BFS(1);
	memset(visited, 0, sizeof(visited));
	maxw = 0;
	BFS(startv);
	printf("%d", maxw);
	return 0;
}
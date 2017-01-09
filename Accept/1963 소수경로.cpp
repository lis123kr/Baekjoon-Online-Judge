#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool visited[10001];
vector < pair<int, int> > CheckNeighbor(const vector<int> &pri, pair<int,int> cmp) {
	vector < pair<int,int> > nei;	
	int weight = cmp.second + 1;
	int cnt = 0;
	for (int i = 0; i < pri.size(); i++) {
		if (pri[i] / 1000 != cmp.first / 1000) cnt++;
		if (pri[i] / 100 %10 != cmp.first /100 % 10) cnt++;
		if (pri[i] / 10 %10 != cmp.first /10 %10) cnt++;
		if (pri[i] % 10 != cmp.first % 10 ) cnt++;

		if (cnt == 1 && !visited[pri[i]]) {
			nei.push_back(make_pair(pri[i], weight));
			visited[pri[i]] = true;
		}
		cnt = 0;
	}
	return nei;
}

int main() {
	freopen("input.txt", "r", stdin);
	int t, idx=0;
	scanf("%d", &t);
	vector<int>pri;
	for (int i = 1000; i < 10000; i++) {
		bool chk = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				chk = false;
				break;
			}			
		}
		if (chk)
			pri.push_back(i);
	}
	
	while (t--) {
		int source, dest, next, weight;
		queue< pair<int, int> > q;		
		scanf("%d %d", &source, &dest);
		if (source == dest) {
			printf("0\n");
			continue;
		}
		visited[source] = true;
		vector< pair<int, int> > nei = CheckNeighbor(pri, make_pair(source, 0));

		for (int i = 0; i < nei.size(); i++)
			q.push(nei[i]);

		while (!q.empty()) {
			next = q.front().first;
			weight = q.front().second;
			q.pop();

			if (next == dest) break;

			visited[next] = true;
			nei = CheckNeighbor(pri, make_pair(next, weight));
			for (int i = 0; i < nei.size(); i++)
				q.push(nei[i]);
		}
		printf("%d\n", weight);
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}
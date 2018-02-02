#include<stdio.h>
#include<queue>
using namespace std;
int f, s, g, u, d;
bool chk[1000001];
int bfs(int x) {
	queue< pair<int, int> >q;
	q.push(make_pair(x, 0));
	chk[x] = true;
	int ans = 1e9;
	while (!q.empty()) {
		auto c = q.front(); q.pop();
		if (c.first == g)
			ans = min(c.second, ans);
		int uu = c.first + u > f ? c.first : c.first + u;
		if (!chk[uu]) {
			chk[uu] = true;
			q.push(make_pair(uu, c.second+1));
		}
		int dd = c.first - d < 1 ? c.first : c.first - d;
		if (!chk[dd]) {
			chk[dd] = true;
			q.push(make_pair(dd, c.second + 1));
		}
	}
	return ans;
}
int main() {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	int ans = bfs(s);
	if (s == g)
		printf("0\n");	
	else if (ans == 1e9)
		printf("use the stairs\n");
	else
		printf("%d\n", ans);
	return 0;
}
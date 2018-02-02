#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int u, v, w;
	//bool operator < (const node &other) const {
	//	return w < other.w;
	//}
};
int parent[10001];
bool cmp(const node &a, const node &b) {
	if (a.w < b.w) return true;
	else return false;
}
int Find(int x) {
	if (x == parent[x]) 
		return x;
	else 
		return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}
int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	vector<node> V(e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &V[i].u, &V[i].v, &V[i].w);
	}
	sort(V.begin(), V.end(), cmp);
	int ans = 0;
	for (int i = 0; i < e; i++) {
		node tmp = V[i];
		int x = Find(tmp.u);
		int y = Find(tmp.v);
		if (x!=y) {
			Union(tmp.u, tmp.v);
			ans += tmp.w;
		}
	}
	printf("%d\n", ans);
	return 0;
}
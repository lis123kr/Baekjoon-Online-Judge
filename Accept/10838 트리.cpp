#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#define MAX 100011
using namespace std;
struct Node {
	int parent, pcolor;
	Node() { parent = pcolor = 0; };
}tree[MAX];
int cnt[300011], parent[MAX];
int LCA(int u, int v, int k) {
	if (u == v)
		return u;
	int i = 0;
	while (u != -1 && i++<= 1000) {
		parent[u] = k;
		u = tree[u].parent;
	}
	i = 0;
	while (v!= -1 && i++<=1000) {
		if (parent[v] == k)
			break;
		v = tree[v].parent;
	}
	return v;
}
int par(int a, int  b, int k) {
	if (a == b) return a;
	parent[a] = k;
	for (int i = 1; tree[a].parent != -1 && i <= 1010; i++) {
		a = tree[a].parent;
		parent[a] = k;
	}
	if (parent[b] == k) return b;
	for (int i = 1; tree[b].parent != -1 && i <= 1010; i++) {
		b = tree[b].parent;
		if (parent[b] == k) break;
	}
	return b;
}
void paint(int u, int v, int c, int p) {
	while (u != p) {
		tree[u].pcolor = c;
		u = tree[u].parent;
	}
	while (v != p) {
		tree[v].pcolor = c;
		v = tree[v].parent;
	}
}

int count(int u, int v, int c, int p) {
	int cc = 0;
	while (u != p && u != 0) {
		if (cnt[tree[u].pcolor] != c) {
			cc++;
			cnt[tree[u].pcolor] = c;
		}
		u = tree[u].parent;
	}
	while (v != p && v != 0) {
		if (cnt[tree[v].pcolor] != c) {
			cc++;
			cnt[tree[v].pcolor] = c;
		}
		v = tree[v].parent;
	}
	return cc;
}

int main() {
	int i, n, k, r, a, b, c, cc=1, pp;
	map<int, int> m;
	m[0] = 1;
	scanf("%d %d", &n, &k);
	tree[0].parent = -1;
	for (i = 1; i <= k; i++) {
		scanf("%d %d %d", &r, &a, &b);
		switch (r){
		case 1:
			scanf("%d", &c);
			if (!m[c]) {
				cc += 1;
				m[c] = cc;
			}
			c = m[c] - 1;
			pp = LCA(a, b,i);
			paint(a, b, c, pp);
			break;
		case 2:
			tree[a].parent = b;
			break;
		case 3:
			pp = LCA(a, b,i);
			printf("%d\n",count(a, b, i, pp));
			break;
		}
	}
	return 0;
}

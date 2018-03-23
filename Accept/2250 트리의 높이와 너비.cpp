#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct nodes {
	int parent, left, right, level;
	nodes() { left = right = -1; }
}node[10001];
int n;
pair<int, int> ans[10001];
int value = 1;
int postorder(int p, int level) {
	if (p == -1) return 0;
	postorder(node[p].left, level+1);
	if (ans[level].first > value)
		ans[level].first = value;
	if (ans[level].second < value)
		ans[level].second = value;
	value++;
	postorder(node[p].right, level+1);	
}
int main() {
	int a, b, c, root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);		
		node[a].left = b;
		node[a].right = c;
		if (b != -1) node[b].parent = a;
		if (c != -1) node[c].parent = a;
	}
	for (int i = 1; i <= n; i++) {
		ans[i].first = 1e9;		
		if (node[i].parent == 0) {
			root = i;
		}
	}	
	postorder(root, 1);
	int rans = 0, rlevel;
	for (int i = 1; i <= n; i++) {
		if (ans[i].first != 1e9 && ans[i].first != 1e9) {
			if (rans < ans[i].second - ans[i].first + 1) {
				rans = ans[i].second - ans[i].first + 1;
				rlevel = i;
			}
		}
	}
	printf("%d %d\n", rlevel, rans);
	return 0;
}
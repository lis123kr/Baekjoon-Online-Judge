#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1000000000;
int n, m, A[100001];
void init(vector< pair<int, int> >& Tree, int node, int start, int end) {
	if (start == end) {
		Tree[node].second = Tree[node].first = A[start];
	}
	else {
		int mid = (start + end) / 2;
		init(Tree, node * 2, start, mid);
		init(Tree, node * 2 + 1, mid + 1, end);
		Tree[node].first = min(Tree[node * 2].first, Tree[node * 2 + 1].first);
		Tree[node].second = max(Tree[node * 2].second, Tree[node * 2 + 1].second);
	}
}
int query(vector< pair<int, int> >&Tree, int node, int start, int end, int s1, int s2, int flag) {
	if (s2 < start || end < s1) {
		return (flag == 1) ? INF : -INF;
	}
	if (s1 <= start && end <= s2) {
		return (flag == 1) ? Tree[node].first : Tree[node].second;
	}
	else {
		int mid = (start + end) / 2;
		int m1 = query(Tree, node * 2, start, mid, s1, s2, flag);
		int m2 = query(Tree, node * 2 + 1, mid + 1, end, s1, s2, flag);
		return (flag==1)? min(m1, m2) : max(m1,m2);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	vector< pair<int,int> >Tree(4 * n); // ±ÍÂúÀ¸¸é 4n°³
	for (int i = 1; i <= n; i++) scanf("%d", A + i);
	init(Tree, 1, 1, n);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", query(Tree, 1, 1, n, a, b, 1), query(Tree, 1, 1, n, a, b, 2));
	}
	return 0;
}
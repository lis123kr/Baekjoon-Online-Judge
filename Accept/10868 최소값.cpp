#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1000000000;
int n, m, A[100001];
void init(vector<int>& Tree, int node, int start, int end) {
	if (start == end) {
		Tree[node] = A[start];
	}
	else {
		int mid = (start + end) / 2;
		init(Tree, node * 2, start, mid);
		init(Tree, node * 2 + 1, mid + 1, end);
		Tree[node] = min(Tree[node*2] , Tree[node*2+1]);
	}
}
int query(vector<int>&Tree, int node, int start, int end, int s1, int s2) {
	if (s2 < start || end < s1) return INF;
	if (s1 <= start && end <= s2) return Tree[node];
	else {
		int mid = (start + end) / 2;
		int m1 = query(Tree, node * 2, start, mid, s1, s2);
		int m2 = query(Tree, node * 2 + 1, mid + 1, end, s1, s2);
		return min(m1, m2);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	vector<int>Tree(4*n); // ±ÍÂúÀ¸¸é 4n°³
	for (int i = 1; i <= n; i++) scanf("%d", A + i);
	init(Tree, 1, 1, n);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", query(Tree, 1, 1, n, a, b));
	}
	return 0;
}
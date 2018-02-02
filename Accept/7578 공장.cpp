#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
pair<int,int>AB[3][500001];
vector<int>Tree(2000000);
void init(int node, int start, int end) {
	if (start == end) Tree[node] = 0;
	else {
		int mid = (start + end) / 2;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
	}
}
int query_sum(int node, int start, int end, int s1, int s2) {
	if (s2 < start || end < s1) return 0;
	if (s1 <= start && end <= s2) return Tree[node];
	int mid = (start + end) / 2;
	int m1 = query_sum(node * 2, start, mid, s1, s2);
	int m2 = query_sum(node * 2 + 1, mid + 1, end, s1, s2);
	return m1 + m2;
}
void update(int node, int start, int end, int index, int val) {
	if (index < start || end < index) return;
	if (start == end) { Tree[node] = val; return; }
	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, val);
	update(node * 2 + 1, mid + 1, end, index, val);
	Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &AB[0][i].first); AB[2][i].first = AB[0][i].second = i; }
	for (int i = 1; i <= n; i++) { scanf("%d", &AB[1][i].first); AB[1][i].second = i; }
	sort(AB[0] + 1, AB[0] + n + 1);
	sort(AB[1] + 1, AB[1] + n + 1);
	for (int i = 1; i <= n; i++) {
		AB[2][AB[0][i].second].second = AB[1][i].second;
	}
	init(1, 1, n);
	long long ans = 0; // int 범위 초과 1번 틀림.
	for (int i = 1; i <= n; i++) {
		ans += (long long)query_sum(1, 1, n, AB[2][i].second, n);
		update(1, 1, n, AB[2][i].second, 1);
	}
	printf("%lld\n", ans);
	return 0;
}
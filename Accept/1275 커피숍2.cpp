#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N, Q;
long long A[100001];
vector<long long>Tree(400001);
const long long INF = 1e9;
void init(int node, int start, int end) {
	if (start == end) {
		Tree[node] = A[start];
	}
	else {
		int mid = (start + end) / 2;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
	}
}
long long query(int node, int start, int end, int s1, int s2) {
	if (s2 < start || end < s1) return 0;
	if (s1 <= start && end <= s2) return Tree[node];
	int mid = (start + end) / 2;
	long long m1 = query(node * 2, start, mid, s1, s2);
	long long m2 = query(node * 2 + 1, mid + 1, end, s1, s2);
	return m1 + m2;
}
void update(int node, int start, int end, int index, int value) {
	if (end < index || index < start) return;
	if (start == end) {
		Tree[node] = value;
	}
	else {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, value);
		update(node * 2 + 1, mid + 1, end, index, value);
		Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
	}
}
int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	init(1, 1, N);
	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if(x>y)
			printf("%lld\n", query(1, 1, N, y, x));
		else
			printf("%lld\n", query(1, 1, N, x, y));
		update(1, 1, N, a, b);
	}
	return 0;
}
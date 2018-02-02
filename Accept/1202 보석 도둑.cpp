#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
int n, k, K[300001];
pair<int, int> VM[300001];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first < b.first) return false;
	else if (a.first == b.first) {
		return a.second < b.second;
	}
	else return true;
}
int main() {
	multiset<int>s;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &VM[i].second, &VM[i].first);
	for (int i = 0; i < k; i++) {
		scanf("%d", &K[i]);
		s.insert(K[i]);
	}
	sort(VM, VM + n, cmp);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(VM[i].second);
		if (it != s.end()) {
			ans += VM[i].first;
			s.erase(it);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
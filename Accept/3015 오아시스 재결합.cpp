#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
int arr[500001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	stack< pair<int, int> > s;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		pair<int, int>p = { arr[i],1 };
		while (!s.empty()) {
			if (s.top().first <= arr[i]) {
				ans += (long long)s.top().second;
				if (s.top().first == arr[i])
					p.second += s.top().second;
				s.pop();
			}
			else {
				break;
			}
		}
		if (!s.empty()) ans += 1LL;
		s.push(p);
	}
	printf("%lld\n", ans);
	return 0;
}
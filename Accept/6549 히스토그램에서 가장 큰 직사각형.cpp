#include<iostream>
#include<stack>
#include<string.h>
#include<vector>
using namespace std;
long long v[100000], space[100000];
int left_[100000];
int main() {
	int n;
	while (true) {
		memset(v, 0, sizeof(v));
		memset(space, 0, sizeof(space));
		memset(left_, -1, sizeof(left_));
		cin >> n;
		if (n == 0) return 0;		
		stack< pair<long long,int> > s;
		for (int i = 0; i < n; i++) cin >> v[i];
		s.push(make_pair(v[0],0));
		left_[0] = -1;
		for (int i = 1; i < n; i++) {
			while (!s.empty()) {
				if (s.top().first <= v[i]) {
					left_[i] = s.top().second;
					break;
				}
				left_[i] = left_[s.top().second];
				space[ s.top().second ] = (long long)s.top().first * (i - left_[s.top().second]-1);
				s.pop();
			}
			s.push(make_pair(v[i],i));			
		}
		while (!s.empty()) {
			space[ s.top().second ] = (long long)s.top().first * (n - left_[s.top().second]-1);
			s.pop();
		}
		long long ans = 0;
		for (int i = 0; i < n; i++)
			if (ans < space[i]) ans = space[i];
		cout << ans << endl;
	}
	return 0;
}
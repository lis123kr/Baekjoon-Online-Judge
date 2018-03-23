#include<cstdio>
#include<vector>
#include<algorithm>
int n, port[40001];
std::vector<int>v;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &port[i]);
	v.push_back(port[1]);
	for (int i = 2; i <= n; i++) {
		if (v.back() < port[i])
			v.push_back(port[i]);
		else {
			auto e = std::lower_bound(v.begin(), v.end(), port[i]) - v.begin();
			v[e] = port[i];
		}
	}
	printf("%d\n", v.size());
	return 0;
}
//¤Ð¤Ð ½Ã°ø ½È¾î
//#include<cstdio>
//#include<vector>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int n, D[11111];
//long long P[11111], W[11111];
//int dp(vector< pair< long long, long long > >& v,int p, long long x) {
//	if (p == n)
//		return 0;
//	if (D[p] != -1)
//		return D[p];
//	if (x+v[p].second < v[p].first) {
//		return D[p] = min(dp(v, p + 1, x + v[p].second) + 1, dp(v, p + 1, v[p].first));
//	}
//	else if (x <= v[p].first) {
//		return D[p] = dp(v, p + 1, x + v[p].second);
//	}
//	else if (x > v[p].first) {
//		return D[p] = dp(v, p + 1, x + v[p].second) + 1;
//	}
//}
//int main() {
//	scanf("%d", &n);
//	vector< pair< long long, long long > > v(n);
//	for (int i = 0; i < n; i++) {
//		scanf("%lld", &v[i].first);
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%lld", &v[i].second);
//	}
//	sort(v.begin(), v.end());
//	memset(D, -1, sizeof(D));
//	printf("%d\n", dp(v, 0, -999999999LL));
//	return 0;
//}
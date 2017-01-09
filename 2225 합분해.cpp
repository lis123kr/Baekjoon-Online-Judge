#include <iostream>

using namespace std;
int n, k;
//D(p,q,k) =  ∑i:0~n ( D( p , q+i, k+1)  )	#p+1로하면 최대 한번
//											#p로하면 중복 가능..
int cache[201][201][201];
int dp(int p, int q,int K) {
	unsigned long long h = 0;
	int &ret = cache[p][q][K];
	if (K > k) return 0;
	if (p == n + 1)return 0;
	if (q == n) return 1;
	if (q > n)return 0;	//런타임에러 이유
	if (ret != 0) return ret;
	for (int i = 0; i <= n; i++)
		h += dp(p, q + i, K + 1) % 1000000000;	//
	return ret = h %1000000000;
}
int D[201][201][201];
int main(){
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	cout << dp(0, 0, 0) << endl;
	return 0;
}

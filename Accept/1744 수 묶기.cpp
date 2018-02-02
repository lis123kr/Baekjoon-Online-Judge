#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int x, zero=0, one=0;
	vector<int>plus, minus;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 1) one++;
		else if (x > 0)plus.push_back(x);
		else if (x < 0) minus.push_back(x);
		else zero++;		
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	int ans = one;
	reverse(plus.begin(), plus.end());
	if (plus.size() % 2 == 1) plus.push_back(1);
	if (minus.size() % 2 == 1) minus.push_back(zero > 0 ? 0 : 1);
	for (int i = 0; i < plus.size(); i += 2) ans += plus[i] * plus[i + 1];
	for (int i = 0; i < minus.size(); i += 2) ans += minus[i] * minus[i + 1];
	printf("%d\n", ans);
	return 0;
}
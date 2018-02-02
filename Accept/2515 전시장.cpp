#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
pair<int, int>pic[300001];
int N, S, D[300001];
// 정렬되있어서 빠르게 검색가능...
int dp(int p) {
	if (p == N)
		return 0;
	int &ret = D[p];
	if (ret != -1)
		return ret;
	return ret = max(dp(p + 1),	
		dp((lower_bound(pic + p, pic + N, make_pair(pic[p].first + S, 0)) - pic)) + pic[p].second);
}
int main() {
	memset(D, -1, sizeof(D));
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &pic[i].first, &pic[i].second);
	sort(pic, pic + N);
	printf("%d\n", dp(0));
	return 0;
}
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, K;
int main() {
	scanf("%d %d %d", &N, &M, &K);
	vector<int> p;
	if (M+K-1 <= N && N <= M*K) {
		for (int i = 1; i <= N; i++)
			p.push_back(i);
		vector<int>g;
		g.push_back(0);
		g.push_back(K);
		N -= K;
		M -= 1;
		int gs = M == 0 ? 0 : N / M;
		int r = M == 0 ? 0 : N%M;
		for (int i = 0; i < M; i++) {
			g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
			if (r > 0) r -= 1;
		}
		for (int i = 0; i < g.size() - 1; i++) {
			reverse(p.begin() + g[i], p.begin() + g[i + 1]);
		}
		for (int i = 0; i < p.size(); i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
	}
	else {
		printf("-1\n");
	}

	return 0;
}
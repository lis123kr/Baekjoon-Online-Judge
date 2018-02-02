#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int n;
struct cd {
	int fisrt, second;
};
struct cmp{
	bool operator()(const struct cd a, const struct cd b) {
		if (a.fisrt == b.fisrt) return a.second > b.second;
		else return a.fisrt > b.fisrt;
	}
};
int main() {
	priority_queue< cd, vector<cd>, cmp > pq;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			if (pq.empty()) {
				printf("0\n");
				continue;
			}
			struct cd p = pq.top();
			pq.pop();
			printf("%d\n", p.second);
			
		}
		else {
			int b = a;
			if (a < 0)
				a = -a;
			struct cd p = { a, b };
			pq.push(p);
		}
	}
	return 0;
}
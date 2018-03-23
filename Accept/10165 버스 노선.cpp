#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Nodes {
	int num, x, y;
	Nodes(int x, int y, int num) : x(x), y(y), num(num) {};
};
bool cmp(const Nodes a, const Nodes b) {
	if (a.x == b.x) return a.y > b.y;
	else return a.x < b.x;
}
int n, m, chk[500001];
int main() {
	int x, y, my=0;
	scanf("%d%d", &n, &m);
	vector<Nodes> v1, v2;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		if (x < y) {
			v1.push_back(Nodes(x, y, i + 1));
		}
		else {
			my = my > y ? my : y;
			v1.push_back(Nodes(x, y + n, i + 1));
			v2.push_back(Nodes(x, y, i + 1));
		}
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	int size = v1.size(), ty = 0;
	for (int i = 0; i < size; i++) {
		if (v1[i].y <= ty || v1[i].y <= my) {
			chk[v1[i].num] = 1;
		}
		ty = ty > v1[i].y ? ty : v1[i].y;
	}
	size = v2.size();
	ty = -1;
	for (int i = 0; i < size; i++) {
		if (v2[i].y <= ty) {
			chk[v2[i].num] = 1;
		}
		ty = ty > v2[i].y ? ty : v2[i].y;
	}
	for (int i = 1; i <= m; i++) {
		if (chk[i] == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
std::vector< std::pair<int, int> > v(8);
bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%d", &v[i].first);
		v[i].second = i+1;
	}
	std::sort(v.begin(), v.end());
	std::sort(v.begin()+3, v.end(), cmp);
	int sum = 0;
	for (int i = 3; i < 8; i++) {
		sum += v[i].first;		
	}
	printf("%d\n", sum);
	for (int i = 3; i < 8; i++) {
		printf("%d ", v[i].second);
	}
	return 0;
}
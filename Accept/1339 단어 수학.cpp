#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector< int > v;
char word[10][11];
bool chk[26];
int ans, n, map[26];
char w[10];
int solve() {
	int size = v.size();
	int sum = 0;
	for (int i = 0; i < size; i++) {
		map[w[i] - 'A'] = v[i];
	}
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; word[i][j]; j++) {
			if (tmp == 0)
				tmp = map[word[i][j] - 'A'];
			else {
				tmp = tmp * 10 + map[word[i][j] - 'A'];
			}
		}
		sum += tmp;
	}
	return sum;
}
int main() {
	int num=9, idx=0;
	scanf("%d", &n);	
	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
		for (int j = 0; word[i][j]; j++) {
			if (!chk[word[i][j] - 'A']) {
				chk[word[i][j] - 'A'] = true;
				v.push_back(num);
				w[idx] = word[i][j];
				idx++, num--;
			}
		}
	}
	sort(v.begin(), v.end());
	do {
		ans = max(ans, solve());
	} while (next_permutation(v.begin(), v.end()));
	printf("%d\n", ans);
	return 0;
}
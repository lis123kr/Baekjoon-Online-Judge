#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int k;
	int arr[20];
	while (true) {
		scanf(" %d", &k);
		if (k == 0) break;
		vector<int>v;
		for (int i = 0; i < k; i++)scanf("%d", arr + i);
		for (int i = 0; i < k - 6; i++)
			v.push_back(0);
		for (int i = 0; i < 6; i++)
			v.push_back(1);
		vector< vector<int> > ans;
		do {
			vector<int>cur;
			for (int i = 0; i < v.size(); i++)
				if (v[i] == 1) cur.push_back(arr[i]);
			ans.push_back(cur);
		} while (next_permutation(v.begin(), v.end()));
		sort(ans.begin(), ans.end());
		for (auto &v : ans) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << ' ';
			}
			cout << endl;
		}
		printf("\n");
	}
	return 0;
}
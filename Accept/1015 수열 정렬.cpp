#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
	int n, A[1001], ans[1001];
	vector< int > P[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		P[A[i]].push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j < P[i].size(); j++) {
			ans[P[i][j]] = cnt++;
		}
	}	
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
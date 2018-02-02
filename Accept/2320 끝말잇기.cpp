#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int n,g[20][20], ans, visited[20];
string s[20];
void solve(int p,int sum) {
	for (int i = 0; i < n; i++) {
		if (!visited[i] && g[p][i] && s[i][0] == s[i][s[i].length() - 1]) {
			visited[i] = 1;
			sum += s[i].length();
			p = i;
			i = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i] && g[p][i]) {
			visited[i] = 1;
			solve(i, sum + s[i].length());
			visited[i] = 0;
		}
	}
	ans = ans > sum ? ans : sum;
}
int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && s[i][s[i].length() - 1] == s[j][0])
				g[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		solve(i, s[i].length());
	}
	printf("%d\n", ans);
	return 0;
}
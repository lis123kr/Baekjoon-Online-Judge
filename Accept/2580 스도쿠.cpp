#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int arr[10][10];
bool r[10][10], c[10][10], sq[10][10];
int square(int p, int q) {
	return (p / 3) * 3 + (q / 3);
}
void solve(int p) {
	if (p == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		return;
	}
	else {
		int x = p / 9, y = p % 9;
		if (arr[x][y] != 0) {
			solve(p + 1);
		}
		else {
			for (int i = 1; i <= 9; i++) {
				if (!r[x][i] && !c[y][i] && !sq[square(x, y)][i]) {
					r[x][i] = c[y][i] = sq[square(x, y)][i] = true;
					arr[x][y] = i;
					solve(p + 1);
					r[x][i] = c[y][i] = sq[square(x, y)][i] = false;
					arr[x][y] = 0;
				}
			}
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				r[i][arr[i][j]] = c[j][arr[i][j]] = sq[square(i, j)][arr[i][j]] = true;
			}
		}
	}
	solve(0);
	return 0;
}
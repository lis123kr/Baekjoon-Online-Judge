#include<stdio.h>
#include<stdlib.h>
int x33[9][10], row[9][10], col[9][10], board[9][9], chk[9][9][10];
void solve(int p) {
	if (p == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", board[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int r = p / 9, c = p % 9;
	if (board[r][c] != 0)
		solve(p + 1);
	else {
		for (int n = 1; n <= 9; n++) {
			if (!row[r][n] && !col[c][n] && !x33[(r / 3)*3 + c / 3][n]) {
				row[r][n] = col[c][n] = x33[(r / 3)*3 + c / 3][n] = 1;
				board[r][c] = n;
				solve(p + 1);
				row[r][n] = col[c][n] = x33[(r / 3) * 3 + c / 3][n] = 0;
				board[r][c] = 0;
			}
		}
	}
}
int main() {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%1d", &board[i][j]);
			col[j][board[i][j]] = 1;
			row[i][board[i][j]] = 1;
			x33[(i / 3)*3 + j / 3][board[i][j]] = 1;
		}
	}
	solve(0);
	return 0;
}

#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int R, C;
char board[21][21];
bool chk[30];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int solve(int y, int x, bool chk[], int cnt) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
			if (!chk[board[ny][nx] - 'A']) {
				chk[board[ny][nx] - 'A'] = true;
				int next = solve(ny, nx, chk, cnt + 1);
				if (ans < next) ans = next;
				chk[board[ny][nx] - 'A'] = false;
			}
		}
	}
	return ans + 1;
}

// 시간초과
int go(int y, int x, string p) {
	if (y < 0 || x < 0 || x >= C || y >= R) return 0;
	if (p.find(board[y][x]) <= p.length()) return 0;
	string n = p + board[y][x];
	return max(max(go(y - 1, x, n), go(y + 1, x, n)), max(go(y, x + 1, n), go(y, x - 1, n))) + 1;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) scanf(" %c", &board[i][j]);
	chk[board[0][0] - 'A'] = true;
	cout << solve(0, 0, chk, 0) << endl;
	//cout << go(0, 0, "") << endl;;
	return 0;
}
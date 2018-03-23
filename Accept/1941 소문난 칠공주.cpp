#include<stdio.h>
char arr[6][6];
bool chk[1 << 25];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int solve(int s, int cs, int cy) {
	if (cy == 4) return 0;
	if (cs + cy == 7) {
		if (cs >= 4 && !chk[s]) {
			chk[s] = 1;
			return 1;
		}else return 0;
	}	
	int h = 0;
	for (int i = 0; i < 25; i++) {
		if ((1<<i) & s) {
			int y = i / 5, x = i % 5;
			for (int p = 0; p < 4; p++) {
				int ny = y + dy[p], nx = x + dx[p];
				if (0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
					if (!(s & (1 << (ny * 5 + nx)))) {
						h += solve(s | (1 << (ny * 5 + nx)), 
							cs+(arr[ny][nx] == 'S' ? 1 : 0), cy+(arr[ny][nx] == 'Y' ? 1 : 0));
					}
				}
			}
		}
	}
	return h;
}
int main() {
	for(int i=0;i<5;i++)		
		scanf("%s", arr[i]);
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans += solve((1<<(i*5 + j)), (arr[i][j] == 'S' ? 1 : 0), (arr[i][j] == 'Y' ? 1 : 0));
		}
	}
	printf("%d\n", ans);
	return 0;
}
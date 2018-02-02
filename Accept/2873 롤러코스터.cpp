#include<stdio.h>
int r, c;
int happy[1001][1001];
int main() {
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++)scanf("%d", &happy[i][j]);
	if (r % 2 == 0 && c % 2 == 0) {
		int min = happy[1][2], my = 1, mx = 2;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if ((i + j) % 2 == 1 && min > happy[i][j]) {
					min = happy[i][j];
					my = i;
					mx = j;
				}
			}
		}
		int cy = 1, cx = 1;
		for (int i = 1; cy <= r&&i <= r; i++) {
			if (cy != my && cy + 1 != my) {
				for (int j = 1; j < c; j++) {
					printf("%c", cx == 1 ? 'R' : 'L');
				}
				printf("D");
				cy += 1;
				cx = cx == 1 ? c : 1;
				for (int j = 1; j < c; j++) {
					printf("%c", cx == 1 ? 'R' : 'L');
				}
				if(cy < r)
					printf("D");
				cx = cx == 1 ? c : 1;
				cy += 1;
			}
			else {
				bool up = false;
				if (mx != 1) { printf("D"); up = true; }
				for (; cx < c; cx++) {
					printf("R");
					if (cx + 1 != mx) {
						printf("%c", up ? 'U' : 'D');
						up = !up;
					}
				}
				cy += 2;
				if (cy < r) printf("D");
			}
		}
	}
	else {
		if (c % 2 == 0) {
			for (int i = 1; i <= r; i+=2) {
				for (int j = 1; j < c; j++) {
					printf("R");
				}
				if (i == r) break;
				printf("D");
				for (int j = 1; j < c; j++) {
					printf("L");
				}
				printf("D");
			}
		}
		else {
			for (int i = 1; i <= c; i+=2) {
				for (int j = 1; j < r; j++) {
					printf("D");
				}
				if (i == c) break;
				printf("R");
				for (int j = 1; j < r; j++) {
					printf("U");
				}
				printf("R");
			}
		}
	}
	return 0;
}
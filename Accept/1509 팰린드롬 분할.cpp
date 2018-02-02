#include<stdio.h>
#include<string.h>
char pal[2501];
int dp[2501], c[2501][2501], len;
int min(int a, int b) { return a > b ? b : a; }
int ispal(int p, int q) {
	if (p == q) return c[p][q] = 1;
	else if (p == q - 1) return c[p][q] = (pal[p] == pal[q]) ? 1 : 0;
	if (c[p][q]!=-1) return c[p][q];

	if (pal[p] != pal[q]) return c[p][q]=0;
	else return c[p][q] = ispal(p + 1, q - 1);
}
int main() {
	scanf("%s", pal+1);
	len = strlen(pal+1);
	memset(c, -1, sizeof(c));
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= i; j++) {
			ispal(j, i);
		}
	}
	
	dp[0] = 0;
	for (int i = 1; i <= len; i++) {
		dp[i] = -1;
		for (int j = 1; j <= i; j++) {
			if (c[j][i]==1) {
				if(dp[i]==-1 || dp[i] > dp[j-1]+1)
				dp[i] = dp[j-1] + 1;
			}
		}
	}
	printf("%d\n", dp[len]);
	return 0;
}
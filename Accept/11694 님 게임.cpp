//1
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int ans = 0,a,b=0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a != 1) b = 1;
		ans ^= a;
	}
	if (n == 1) {
		if(a==1)
			printf("cubelover\n");
		else
			printf("koosaga\n");
	}
	else {
		if (ans == 0) {
			if (b == 0)
				printf("koosaga\n");
			else
				printf("cubelover\n");
		}
		else {
			if (b == 0)
				printf("cubelover\n");
			else
				printf("koosaga\n");
		}
	}
	return 0;
}

//2
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int ans = 0, a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		ans ^= a;
	}
	if (ans == 0)
		printf("cubelover\n");
	else
		printf("koosaga\n");
	return 0;
}
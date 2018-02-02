#include<stdio.h>
void print0(char c, int n, int f, int f2) {
	switch (n) {
	case 1:
	case 5:
		printf("..%c.", f != 0 ? '*' : '#');
		break;
	case 2:
	case 4:
		printf(".%c.%c", f != 0 ? '*' : '#', f != 0 ? '*' : '#');
		break;
	case 3:
		printf("%c.%c.", f2 != 0 ? '*' : '#', c);
		break;
	}
}
void print(char c, int n, int f, int f2) {
	switch (n) {
	case 1:
	case 5:
		printf("..%c..", f != 0 ? '*' : '#');
		break;
	case 2:
	case 4:
		printf(".%c.%c.", f != 0 ? '*' : '#', f != 0 ? '*' : '#');
		break;
	case 3:
		printf("%c.%c.%c", f2 != 0 ? '*' : '#', c, f != 0 ? '*' : '#');
		break;
	}
}
char a[20];
int main() {
	scanf("%s", a);
	for (int j = 1; j <= 5; j++) {
		for (int i = 0; a[i] != NULL; i++)
			if(a[i+1] != NULL)
				print0(a[i], j, i % 3 == 2, i%3==2 || (i%3 == 0 && i!=0));
			else
				print(a[i], j, i%3==2, i % 3 == 2 || (i % 3 == 0 && i != 0));
		printf("\n");
	}
	return 0;
}
//10953
#include<stdio.h>
int main() {
	int t;
	char tmp[4];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", tmp);
		printf("%d\n", tmp[0] - '0' + tmp[2] - '0');
	}		
	return 0;
}
//2558
#include<stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", a + b);
	return 0;
}
//10950
#include<stdio.h>
int main() {
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
//11022
#include<stdio.h>
int main() {
	int t, a, b, id=1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n",id++,a,b, a + b);
	}
	return 0;
}
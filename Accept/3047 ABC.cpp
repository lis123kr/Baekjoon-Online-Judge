#include<stdio.h>
int main() {
	int n1, n2, n3;
	char ABC[4] = { 0 };
	scanf("%d %d %d %s", &n1, &n2, &n3, ABC);
	for (int i = 0; i < 3; i++) 
		printf("%d ", ABC[i] == 'A' ? n1 > n2 ? n2 > n3 ? n3 : n2 : n1 > n3 ? n3 : n1 : ABC[i] == 'B' ? n1 > n2 ? n1 > n3 ? n2 > n3 ? n2 : n3 : n1 : n2 > n3 ? n1 > n3 ? n1 : n3 : n2 : n1 > n2 ? n1 > n3 ? n1 : n3 : n2 > n3 ? n2 : n3);
	return 0;
}
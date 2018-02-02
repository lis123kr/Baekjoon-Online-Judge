#include<stdio.h>
#define PI 3.1415926535897932384
int main() {
	double r;
	scanf("%lf", &r);
	printf("%.6lf\n%.6lf", r*r*PI, 2 * r*r);
	return 0;
}
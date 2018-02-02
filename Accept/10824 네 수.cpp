#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	unsigned long long re = strtoull(a.c_str(),0,10) + strtoull(c.c_str(), 0, 10);
	printf("%lld", re);
	return 0;
}
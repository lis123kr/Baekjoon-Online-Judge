#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	vector<int>arr(n), ar2(n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	ar2 = arr;
	sort(ar2.begin(), ar2.end());
	int mm=0;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
		vector<int>::iterator a = upper_bound(ar2.begin(), ar2.end(), *it);
		auto b = a - ar2.begin() -1, c = it - arr.begin();
		if (mm < c - b) mm = c - b;
	}
	printf("%d", mm+1);
	return 0;
}
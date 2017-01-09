#include <iostream>
#include <cstdio>
using namespace std;

int n;
int arr[100001], t[100001];

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	long long mmax = 0;
	for (int i = 1; i <= n; i++) {
		t[i] = arr[i];
		if (t[i - 1] + t[i] > t[i])
			t[i] += t[i - 1];
	}
	mmax = t[1];
	for (int i = 1; i <= n; i++) if (mmax < t[i]) mmax = t[i];
	cout << mmax << endl;
	return 0;
}
#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[10];
int main() {
	freopen("input.txt", "r", stdin);
	int a;
	while (scanf("%1d", &a) == 1) {
		arr[a]++;
	}
	for (int i = 9; i >= 0; i--) for (int j = 0; j < arr[i]; j++) printf("%d", i);
	return 0;
}
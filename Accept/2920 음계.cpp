#include<stdio.h>
int main() {
	int arr[8],i, asc=1,desc=1;
	for (i = 0; i < 8; i++)scanf("%d", &arr[i]);
	for (i = 1; i < 8; i++) {
		if (arr[i - 1] < arr[i]) desc = -1;
		if (arr[i - 1] > arr[i]) asc = -1;
	}
	if (desc == -1 && asc == -1) printf("mixed\n");
	else if (desc == 1) printf("descending\n");
	else printf("ascending\n");
	return 0;
}
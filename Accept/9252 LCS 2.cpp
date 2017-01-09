#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char str1[1001], str2[1001];
pair<int, string> arr[2][1001];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%s %s", str1, str2);
	int leng1 = strlen(str1), leng2 = strlen(str2);
	int p, q, m =0;
	for (int i = 1; i <= leng1; i++) {
		for (int j = 1; j <= leng2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				arr[i%2][j].first = arr[(i - 1) % 2][j - 1].first + 1;
				arr[i % 2][j].second = arr[(i - 1) % 2][j - 1].second + str1[i - 1];
			}
			else {
				arr[i % 2][j].first = max(arr[(i - 1) % 2][j].first, arr[i % 2][j - 1].first);
				arr[i % 2][j].second = (arr[(i - 1) % 2][j].first >= arr[i % 2][j - 1].first) ? arr[(i - 1) % 2][j].second : arr[i % 2][j - 1].second;
			}
			if (m < arr[i % 2][j].first) {
				p = i % 2; q = j;
				m = arr[i % 2][j].first;
			}
		}
	}
	printf("%d\n%s", arr[p][q].first, arr[p][q].second.c_str());
	return 0;
}
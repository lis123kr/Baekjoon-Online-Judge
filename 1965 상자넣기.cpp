////#include<cstdio>
////#include<algorithm>
////int n;
////int arr[1001];
////int Max_num[1001];
////int cnt[1001];
////
//////부분 수열 문제 
//////       3
////// 5     2  3
////// 4  5  1  2  3  
////// ㅁ ㅁ ㅁ ㅁ ㅁ
////// 4  5  1  2  3
////
//////캐쉬를 둘 조건이 없음(상자의 크기 명시 x, 또한 메모리 제한)
//////int dp(int i, int j) {
//////	if (i == n) return 0;
//////	if (j < arr[i])
//////		return std::max(dp(i + 1, j), 1 + dp(i + 1, arr[i]));
//////	else
//////		return dp(i + 1, j);
//////}
////
////int main() {
////	freopen("input.txt", "r", stdin);
////	scanf("%d", &n);
////	int max_cnt = 0;
////	for (int i = 0; i < n; i++) {
////		scanf("%d", &arr[i]);
////		Max_num[i] = arr[i];
////		cnt[i] = 1;
////		for (int j = i-1; j >= 0; j--) {
////			if (Max_num[j] < arr[i]) {
////				Max_num[j] = arr[i];
////				cnt[j]++;
////				if (max_cnt < cnt[j]) max_cnt = cnt[j];
////			}
////		}
////	}
////	printf("%d\n", max_cnt);	
////	return 0;
////}

#include <cstdio>
#include <algorithm>
#define MAX 1000
using namespace std;

int box[MAX + 1] = { 0, };
int num[MAX + 1] = { 0, };
int N;

int main()
{
	freopen("input.txt", "r", stdin);
	int result = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &box[i]);
		int maxNum = 0;
		num[i] = 1;
		for (int j = i - 1; j > 0; j--)
		{
			if (box[i] > box[j])
			{
				maxNum = max(num[j], maxNum);
				num[i] = maxNum + 1;
			}
		}
		result = max(result, num[i]);
	}

	printf("%d\n", result);
	return 0;
}
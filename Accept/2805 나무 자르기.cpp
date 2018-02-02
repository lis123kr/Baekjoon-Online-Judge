#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long arr[1000001];
long long res[1000001];
int main() {
	long long N, M;
	scanf("%lld %lld", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);
	sort(arr+1, arr + N+1);
	for (int i = 1; i <= N; i++) res[i] = (arr[i] - arr[i - 1]) * (N - i + 1);
	for (int i = N; i >= 1; i--) res[i] += res[i + 1];
	reverse(res + 1, res + N + 1);
	auto idx = lower_bound(res + 1, res + N + 1, M) - res;
	if (res[idx] == M) printf("%lld\n", arr[N - idx]);
	else if (res[idx] > M) {
		M -= res[idx - 1];
		printf("%lld\n", arr[N-idx+1] - (long long)ceil(((double)M / idx)));
	}
	else {
		M -= res[idx];
		printf("%lld\n", arr[N-idx+1] - (long long)ceil(((double)M / (idx + 1))));
	}
	return 0;
}
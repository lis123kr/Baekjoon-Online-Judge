#include <stdio.h>
#define MAX_K (100000 + 1)
typedef long long LL;
LL LAN[MAX_K];
LL Max;
int N, K;
void solve(LL start, LL end)
{
	LL mid, ret;
	while (start <= end)
	{
		ret = 0;
		mid = (start + end) >> 1;
		for (int i = 1; i <= K; i++)
			ret += (LAN[i] / mid);

		if (ret >= N)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	printf("%lld\n", end);
}

int main()
{
	freopen("input.txt", "r", stdin);
	Max = 0;
	scanf("%d %d", &K, &N);
	for (int i = 1; i <= K; i++)
	{
		scanf("%d", LAN + i);
		if (Max < LAN[i])
			Max = LAN[i];
	}

	solve(0, Max);
	return 0;
}

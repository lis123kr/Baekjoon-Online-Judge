#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int k, m, n, a[1001], b[1001], suma[1001], sumb[1001];
vector<int>v1, v2;
map<int, int> m1, m2;
int main() {
	scanf("%d%d%d", &k, &m, &n);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	for (int i = 1; i <= m; i++) {
		suma[i] = suma[i-1] + a[i];
		if(a[i] <= k)
			v1.push_back(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		sumb[i] = sumb[i - 1] + b[i];
		if(b[i] <= k)
			v2.push_back(b[i]);
	}
	int sum = 0;
	for (int i = 2; i <= m-1; i++) { // 2~m-1개 까지 부분집합을 모두 추가
		// j ~ j+i의 합을  추가
		for (int j = 0; j + i <= m; j++) { 
			sum = suma[j + i] - suma[j];
			if (sum <= k)
				v1.push_back(sum);
		}
		// m - i + 1개 부터 m까지의 합과 1~ 나머지 갯수 까지 합
		for (int j = m - i + 1; j < m; j++) {	
			sum = suma[m] - suma[j] + suma[i - (m - j)];
			if (sum <= k)
				v1.push_back(sum);
		}
	}
	v1.push_back(0);
	if(suma[m] <= k)
		v1.push_back(suma[m]);

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 0; j + i <= n; j++) {
			sum = sumb[j + i] - sumb[j];
			if (sum <= k)
				v2.push_back(sum);
		}
		for (int j = n - i + 1; j < n; j++) {
			sum = sumb[n] - sumb[j] + sumb[i - (n - j)];
			if (sum <= k)
				v2.push_back(sum);
		}
	}
	v2.push_back(0);
	if(sumb[n] <= k)
		v2.push_back(sumb[n]);
	int as = v1.size(), bs = v2.size(), ans = 0;
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < as; i++) {
		if (m1.find(v1[i]) == m1.end())
			m1[v1[i]] = 0;
		m1[v1[i]]++;
	}
	for (int i = 0; i < bs; i++) {
		if (m2.find(v2[i]) == m2.end())
			m2[v2[i]] = 0;
		m2[v2[i]]++;
	}

	for (int i = 1; i < k; i++) {
		if (m1[i] > 0 && m2[k - i] > 0)
			ans += m1[i] * m2[k - i];
	}
	ans += m1[k] + m2[k];
	printf("%d\n", ans);
	return 0;
}
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool possible(double x, double y, double c, double mid) {
	double xx = sqrt(x*x - mid*mid);
	double yy = sqrt(y*y - mid*mid);

	double h = xx*yy / (xx + yy);

	return h > c;
}
int main() {
	double x, y, c;
	while (scanf("%lf %lf %lf", &x, &y, &c) == 3) {
		double low = 0, high = x > y ? y : x;
		double ans = 0;
		while (abs(high - low) > 1e-6) { // 실수이면 low <= high 와 같은 표현 사용 불가
			double mid = (low + high) / 2.0;
			if (possible(x, y, c, mid)) {
				low = mid;				// 실수일 때
				ans = mid;
			}
			else {
				high = mid;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
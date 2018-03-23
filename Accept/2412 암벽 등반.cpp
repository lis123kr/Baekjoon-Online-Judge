#include<stdio.h>
#include<queue>
#include<algorithm>
struct Point {
	int y, x, cnt;
	Point() { cnt = 0; }
	Point(int y, int x, int cnt) :y(y), x(x), cnt(cnt) {};
}points[50001];
bool cmp(const Point a, const Point b) { return a.y < b.y; }
int inline abs(int a) { return a > 0 ? a : -a; }
bool inline chk(const Point a, const Point b) { return abs(a.y - b.y) <= 2 && abs(b.x - a.x) <= 2; }
int n, T, ans;
bool visited[50001];
int main() {
	scanf("%d %d", &n, &T);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &points[i].x, &points[i].y);
	std::sort(points, points + n, cmp);
	std::queue< Point > q;
	q.push(Point(0, 0, 0));
	while (!q.empty()) {
		Point np = q.front(); q.pop();
		if (np.y == T) {
			ans = np.cnt;
			break;
		}
		auto lower = std::lower_bound(points, points + n, Point(np.y-2, 0, 0), cmp) - points;
		auto upper = std::upper_bound(points, points + n, Point(np.y+2, 0, 0), cmp) - points;
		for (int i = lower; i < upper; i++) {
			if (!visited[i] && chk(np, points[i])) {
				visited[i] = true;
				points[i].cnt = np.cnt + 1;
				q.push(points[i]);
			}
		}
	}
	printf("%d\n", ans == 0 ? -1 : ans);
	return 0;
}
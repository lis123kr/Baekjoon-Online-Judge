#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
bool visited[201][201];
// 앞의 두 통의 양만 알면 나머지 하나는 구할 수 있음
// a + b + c = C
// 즉, c = C - a - b;
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	set<int> s;
	s.insert(C);
	queue< pair<int,int> >q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int c = C - a - b;
		q.pop();
		// a -> b
		int na = a, nb = b, nc = c;
		nb += na; na = 0;
		if (nb >= B) {
			na = nb - B;
			nb = B;
		}
		
		if (!visited[na][nb]) {
			visited[na][nb] = true;
			q.push(make_pair(na, nb));
			if (na == 0) {
				s.insert(nc);
			}
		}

		// a -> c
		na = a, nb = b, nc = c;
		nc += na; na = 0;
		if (nc >= C) {			
			na = nc - C;
			nc = C;
		}
		if (!visited[na][nb]) {
			visited[na][nb] = true;
			q.push(make_pair(na, nb));
			if (na == 0) {
				s.insert(nc);
			}
		}

		// b -> a
		na = a, nb = b, nc = c;
		na += nb; nb = 0;
		if (na >= A) {
			nb = na - A;
			na = A;
		}
		if (!visited[na][nb]) {
			visited[na][nb] = true;
			q.push(make_pair(na, nb));
			if (na == 0) {
				s.insert(nc);
			}
		}

		// b -> c
		na = a, nb = b, nc = c;
		nc += nb; nb = 0;
		if (nc >= C) {
			nb = nc - C;
			nc = C;
		}
		if (!visited[na][nb]) {
			visited[na][nb] = true;
			q.push(make_pair(na, nb));
			if (na == 0) {
				s.insert(nc);
			}
		}
		// c -> a
		na = a, nb = b, nc = c;
		na += nc; nc = 0;
		if (na >= A) {
			nc = na - A;
			na = A;
		}
		if (!visited[na][nb]) {
			visited[na][nb] = true;
			q.push(make_pair(na, nb));
			if (na == 0) {
				s.insert(nc);
			}
		}
		// c -> b
		na = a, nb = b, nc = c;
		nb += nc; nc = 0;
		if (nb >= B) {
			nc = nb - B;
			nb = B;
		}
		if (!visited[na][nb]) {
			visited[na][nb] = true;
			q.push(make_pair(na, nb));
			if (na == 0) {
				s.insert(nc);
			}
		}		
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}
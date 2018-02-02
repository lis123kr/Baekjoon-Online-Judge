#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
int main() {
	int a = 0,b;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		if (a == 0) cin >> a;
		else {
			cin >> b;
			a = a * 10 + b;
		}
		if (a % 10 == 0) a += 9;
	}
	map<int, int> m; m[a] = 0;
	queue<int> q; q.push(a);
	while (!q.empty()) {
		int n = q.front(); q.pop();
		string now = to_string(n);
		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) {
				string next = now;
				swap(next[3 * x + y], next[3 * xx + yy]);
				int num = stoi(next);
				if (m.count(num) == 0) {
					m[num] = m[n] + 1;
					q.push(num);
				}
			}
		}
	}
	if (m.count(123456789) == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << m[123456789] << '\n';
	}
	return 0;
}
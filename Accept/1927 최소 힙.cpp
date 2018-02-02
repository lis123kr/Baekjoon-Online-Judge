#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int main() {
	int n, input;
	cin >> n;
	priority_queue<int>pq;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				input = -pq.top();
				pq.pop();
				cout << input << '\n';
			}
		}
		else {
			pq.push(-input);
		}
	}

	return 0;
}
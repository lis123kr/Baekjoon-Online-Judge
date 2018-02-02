#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	string op;
	deque<int>q;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> op;
		if (op == "push_back") {
			scanf("%d", &a);
			q.push_back(a);
		}
		else if (op == "push_front") {
			scanf("%d", &a);
			q.push_front(a);
		}
		else if (op == "front") {
			q.empty() ? printf("-1\n") : printf("%d\n", q.front());
		}
		else if (op == "back")
			q.empty() ? printf("-1\n") : printf("%d\n", q.back());
		else if (op == "pop_front") {
			if (q.empty())
				printf("-1\n");
			else {
				printf("%d\n", q.front()); q.pop_front();
			}
		}
		else if (op == "pop_back") {
			if (q.empty())
				printf("-1\n");
			else {
				printf("%d\n", q.back()); q.pop_back();
			}
		}
		else if (op == "size")
			printf("%d\n", q.size());
		else
			printf("%d\n", q.empty());
	}
	return 0;
}
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
	queue<int>q;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> op;
		if (op == "push") {
			scanf("%d", &a);
			q.push(a);
		}
		else if (op == "front") {
			q.empty() ? printf("-1\n") : printf("%d\n", q.front());
		}
		else if (op == "back")
			q.empty() ? printf("-1\n") : printf("%d\n", q.back());
		else if (op == "pop") {
			if (q.empty())
				printf("-1\n");
			else {
				printf("%d\n", q.front()); q.pop();
			}			 
		}
		else if (op == "size")
			printf("%d\n", q.size());
		else
			printf("%d\n", q.empty());			
	}
	return 0;
}
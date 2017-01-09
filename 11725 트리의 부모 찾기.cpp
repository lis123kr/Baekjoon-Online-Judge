#include<cstdio>
#include<vector>
using namespace std;
struct node {
	int val;
	int parent;
	vector<struct node*>children;
};
int n;
vector< struct node > arr;
bool visited[100001];
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < arr[v].children.size(); i++) {
		if (!visited[arr[v].children[i]->val]) {
			visited[arr[v].children[i]->val] = true;
			arr[v].children[i]->parent = arr[v].val;
			dfs(arr[v].children[i]->val);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int a, b;
	arr = vector< struct node >(n + 1);
	for (int i = 1; i <= n; i++) arr[i].val = i;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		arr[a].children.push_back(&arr[b]);
		arr[b].children.push_back(&arr[a]);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) printf("%d\n", arr[i].parent);
	return 0;
}
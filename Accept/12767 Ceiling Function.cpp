#include<iostream>
#include<string>
#include<set>
using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;
	node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};

void add(struct node** p, int c) {
	if (*p == NULL) {
		struct node* new_node = new struct node();
		new_node->data = c;
		*p = new_node;
		return;
	}
	else {
		if ((*p)->data < c) {
			add(&(*p)->right, c);
		}
		else {
			add(&(*p)->left, c);
		}
	}
}

string preorder(struct node* p) {
	string s = "";
	if (p == NULL) return s;
	if (p->left != NULL && p->right != NULL) {
		s += "3";
	}
	else if (p->left != NULL) {
		s += "2";
	}
	else if (p->right != NULL) {
		s += "1";
	}
	else {
		s += "0";
		return s;
	}
	s+=preorder(p->left);
	s+=preorder(p->right);
	return s;
}

int main() {
	int n, k, a;
	cin >> n >> k;
	set<string> s;

	for (int i = 0; i < n; i++) {

		struct node *root=NULL;
		for (int j = 0; j < k; j++) {
			cin >> a;
			add(&root, a);
		}
		s.insert(preorder(root));
	}
	cout << s.size() << endl;
	return 0;
}
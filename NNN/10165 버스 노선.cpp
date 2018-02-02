//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//struct Node {
//	int num, x, y;
//	struct Node *left, *right;
//
//	struct Node(int num, int x,int y) : num(num), x(x),y(y) { left = right = NULL; }
//};
//struct Node *root;
//bool chk[500001];
//void init(struct Node **p, int num, int x2,int y2) {
//	if (*p == NULL) {
//		(*p) = new Node(num, x2, y2);
//		chk[num] = true;
//		return;
//	}
//	else {
//		int x1 = (*p)->x, y1 = (*p)->y;
//		if (y1 == y2) {
//			if (x1 > y1) {
//				if (x1 >= x2 && x2 > y2) {
//					chk[(*p)->num] = false;
//					(*p)->num = num;
//					(*p)->x = x2;
//					chk[num] = true;
//					return;
//				}
//				else if (x1 >= x2 && x2 < y2) {
//					return;
//				}
//			}
//			else {
//				if (x1 >= x2) {
//					chk[(*p)->num] = false;
//					(*p)->num = num;
//					(*p)->x = x2;
//					chk[num] = true;
//					return;
//				}
//				else if (x1 <= x2 && x2 > y2) {
//					chk[(*p)->num] = false;
//					(*p)->num = num;
//					(*p)->x = x2;
//					chk[num] = true;
//					return;
//				}
//				else if (x1 <= x2 && x2 < y2) {
//					return;
//				}
//			}
//		}
//		else if (y1 > y2) {
//			if (x1 > y1) {
//				if (x2 < y2 && x1 <= x2) return;
//				else if (x2 > y2 && x1 <= x2) return;
//			}
//			else {
//				if (x1 <= x2 && x2 < y2)
//					return;
//			}
//		}
//		else { // y1 < y2
//			if (x1 > y1) {
//				if (x2 > y2 && x1 >= x2) {
//					chk[(*p)->num] = false;
//					(*p)->num = num;
//					(*p)->x = x2;
//					chk[num] = true;
//					return;
//				}
//			}
//			else {
//				if (x2 <= x1 || y2 < x2) {//////////
//					chk[(*p)->num] = false;
//					(*p)->num = num;
//					(*p)->x = x2;
//					chk[num] = true;
//					return;
//				}
//			}
//		}
//		
//		if (y1 > y2) {
//			if ((*p)->left == NULL) {
//				(*p)->left = new Node(num, x2, y2);
//				chk[num] = true;
//				return;
//			}
//			init(&(*p)->left, num, x2, y2);
//		}
//		else {			
//			if ((*p)->right == NULL) {
//				(*p)->right = new Node(num, x2, y2);
//				chk[num] = true;
//				return;
//			}
//			init(&(*p)->right, num, x2, y2);
//		}		
//	}
//}
//int main() {
//	int n, m ,x,y;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= m; i++) {
//		scanf("%d %d", &x,&y);
//		init(&root, i, x, y);
//	}
//	for (int i = 1; i <= m; i++) {
//		if (chk[i])
//			printf("%d ", i);
//	}
//	return 0;
//}
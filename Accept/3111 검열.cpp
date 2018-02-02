//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//
//#define MAXT 300000
//#define MAXA 25
//
//int lenA, lenT;
//char T[MAXT + 1];
//char A[MAXA + 1];
//
//struct stack {
//	int top;
//	char x[MAXT + 1];
//	char w[MAXA];
//
//	void init(char *A) {
//		for (int i = 0; i < lenA; ++i) w[i] = A[lenA - 1 - i];
//		top = 0;
//	}
//
//	int add(char c) {
//		int ret = 0;
//		x[top++] = c;
//		if (top >= lenA) {
//			ret = 1;
//			for (int i = 0; i < lenA; ++i)
//				if (x[top - i - 1] != w[i])
//					ret = 0;
//			if (ret) top -= lenA;
//		}
//		return ret;
//	}
//} L, D;
//
//int main(void) {
//	gets_s(A); lenA = strlen(A);
//	gets_s(T); lenT = strlen(T);
//	L.init(A);
//	std::reverse(A, A + lenA);
//	D.init(A);
//
//	int turn = 0;
//	int lpos = 0, dpos = lenT - 1;
//	while (lpos <= dpos)
//		if (turn == 0) turn ^= L.add(T[lpos++]);
//		else turn ^= D.add(T[dpos--]);
//
//		while (L.top) D.add(L.x[--L.top]);
//
//		while (D.top) printf("%c", D.x[--D.top]);
//		printf("\n");
//
//		return 0;
//}
//
//


#include<algorithm>
#include<cstdio>
#include<cstring>
#define MAXA	25
#define MAXT	300000
using namespace std;
int lenA, lenT;
char A[MAXA + 1], T[MAXT +1];
struct stack {
	char w[MAXA + 1];
	char x[MAXT + 1];
	int top;
	void init(char *str) {
		top = 0;
		for (int i = 0; i < lenA; i++) w[i] = A[lenA - i - 1];
	}
	int add(char c) {
		x[top++] = c;
		int ret = 0;
		if (top >= lenA) {
			ret = 1;
			for (int i = 0; i < lenA; i++)
				if (x[top - i - 1] != w[i])
					ret = 0;
			if (ret) top -= lenA;
		}
		return ret;
	}
}L, R;
int main() {
	scanf("%s %s", A, T);
	lenA = strlen(A), lenT = strlen(T);
	L.init(A);
	reverse(A, A + lenA);
	R.init(A);
	int lpos = 0, rpos = lenT - 1;
	int turn = 0;
	while (lpos <= rpos)
		if (turn == 0) turn ^= L.add(T[lpos++]);
		else turn ^= R.add(T[rpos--]);

	while (L.top) R.add(L.x[--L.top]);
	while (R.top) printf("%c", R.x[--R.top]);
	printf("\n");
	return 0;
}
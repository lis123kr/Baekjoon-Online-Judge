#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
char m[100001];
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%s", m);
	int leng = strlen(m), L=0, cnt=0;
	vector<char>v;
	for (int i = 0; i < leng; i++) {
		if (m[i] == '(') {
			if (i + 1 < leng && m[i + 1] == ')') v.push_back('L'),i++;
			else v.push_back(m[i]);
		}
		else {
			for (int j = v.size() - 1; j >= 0; j--) {
				if (v[j] == 'L') L++;
				else cnt += L + 1, L = 0, v.erase(v.begin()+j),j=0;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
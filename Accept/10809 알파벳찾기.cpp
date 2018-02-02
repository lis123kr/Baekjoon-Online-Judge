#include<iostream>
#include<string.h>
#include<string>
using namespace std;
string s;
int arr[33];
int main() {
	cin >> s;
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < s.length(); i++) {
		int idx = s.find_first_of(s[i]);
		arr[s[i] - 'a'] = idx;		
	}
	for (int i = 0; i < 26; i++)
		cout<<arr[i]<<" ";
	return 0;
}
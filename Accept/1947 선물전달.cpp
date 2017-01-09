#include<iostream>
int n;
int main() {
	std::cin >> n;
	long long int dp[3] = { 0,0,1 };
	for (int i = 3; i <= n; i++) {
		dp[i%3] = (i - 1) * (dp[(i - 1)%3] + dp[(i - 2)%3]) % 1000000000;
	}
	std::cout << dp[n%3] % 1000000000 << std::endl;
	return 0;
}
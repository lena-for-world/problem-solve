#include <iostream>
using namespace std;

int num[1001], dp[1001], n, mx = -2;

int len(int idx) {
	if(dp[idx] != -1) return dp[idx];
	dp[idx] = 1;
	for(int i = idx + 1; i < n; i++) {
		if(num[idx] < num[i]) dp[idx] = max(len(i)+1, dp[idx]);
	}
	return dp[idx];
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> num[i];
		dp[i] = -1;
	}
	for(int i = 0; i < n; i++) {
		mx = max(mx, len(i));
	}
	cout << mx;
	return 0;
}

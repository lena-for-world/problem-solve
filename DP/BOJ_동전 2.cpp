#include <iostream>
#define MAX 987654321
using namespace std;

int coin[101];
int n, k;
int dp[10001];

int func(int sum, int cnt) {
	if(sum > k) return MAX;
	if(sum == k) {
		return 0;
	}
	if(dp[sum] != 0) return dp[sum];
	dp[sum] = MAX; // 최소를 찾기 위함
	for(int i= 0; i < n; i++) {
		dp[sum] = min(dp[sum],func(sum+coin[i], cnt+1) + 1);
	}
	return dp[sum];
}

int main() {
	cin >> n >> k;
	for(int i = 0 ;i < n; i++) {
		cin >> coin[i]; 
	}
	int a = func(0,0);
	if(a == MAX) {
		cout << -1;
	} else cout << a;
	return 0;
}

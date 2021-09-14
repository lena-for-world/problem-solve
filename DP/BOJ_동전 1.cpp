#include <iostream>
using namespace std;

int n, k;
int dp[100001];
int coin[101];

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n;i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
  // 각 동전을 가지고 j라는 합을 구해나가야 중복된 경우를 세지 않을 수 있다
	for(int i= 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(j-coin[i] >= 0) dp[j] += dp[j-coin[i]];
		}
	}
	cout << dp[k];
	return 0;
}

/**
*
탑다운으로는 못 푸는 문제인가...?
메모리 제한이 있어서 2차원으로 동전 개수를 고려할 수 없음
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> boxes;
int dp[1001];
int ans = 0;

int main() {
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		boxes.push_back(a);
		dp[i] = 0;
	}
	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(boxes[i] > boxes[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}

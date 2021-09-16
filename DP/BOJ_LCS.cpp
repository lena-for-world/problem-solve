#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string st1, st2;

int find(int base, int idx) {
	if(base == st1.size() || idx == st2.size()) return 0;
	int& ret = dp[base][idx];
	if(ret != -1) return dp[base][idx];
	ret = 0;
	if(st1[base] == st2[idx]) {
		ret = max(ret, find(base+1, idx+1)+1);
	} else {
		ret = max(find(base, idx+1), find(base+1, idx));
	}
	return ret;
}

int main() {
	int mx = -2;
	cin >> st1 >> st2;
	for(int i = 0; i < 1001; i++) {
		for(int j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
	cout << find(0,0);
	return 0;
}

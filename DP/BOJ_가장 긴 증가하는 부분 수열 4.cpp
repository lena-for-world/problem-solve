#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, nans = -1, ntemp = 0;

int dp[1001]; // 시작하는 인덱스

int func(int idx) {
	int& ret = dp[idx];
	if(ret != -1) return ret;
	ret = 1;
	for(int i = idx+1; i < n; i++) {
		if(v[idx] < v[i]) {
			ret = max(ret, func(i)+1);
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i< n ;i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for(int i = 0; i < 1001; i++) dp[i] = -1;
	for(int i = 0; i < n; i++) {
		int temp = func(i);
		nans = max(nans, temp);
	}
	int t = nans;
	cout << nans <<'\n';
	for(int i = 0; i< n; i++) {
		if(dp[i] == t && dp[i] != -1) {
			cout << v[i] << " ";
			t--;
		}
	}
	return 0;
}

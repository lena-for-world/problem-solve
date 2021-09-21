#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> ans;

void checkingNum(int len, string st) {
	if(len == 0) {
		long long num = stol(st);
		ans.push_back(num);
		return;
	}
	int firstNum = -1;
	if(st.size() != 0) firstNum = st[0] - '0';
	for(int i = firstNum + 1; i < 10; i++) {
		string temp = "";
		temp += (i+'0');
		checkingNum(len-1, temp + st);
	}
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i< 10; i++) {
		checkingNum(i, "");
	}
	ans.push_back(9876543210);
	sort(ans.begin(), ans.end());
	if(n >= ans.size()) cout << -1;
	else cout << ans[n];
	return 0;
}

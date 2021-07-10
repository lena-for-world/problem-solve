#include <iostream>
using namespace std;

string check(string ans, int cnt) {
	int four = cnt / 4;
	cnt %= 4;
	if(cnt == 0) for(int a=0; a < four; a++) ans += "AAAA";
	else {
		int two = cnt / 2;
		cnt %= 2;
		for(int a=0; a < four; a++) ans += "AAAA";
		for(int a=0; a < two; a++) ans += "BB";
	}
	return ans;
}

int main() {
	string st;
	string ans = "";
	cin >> st;
	int i = 0, flag = 0;
	int cnt = 0;
	if(st[0] != '.') {
		if(st.size()==1) {
			cout << -1;
			return 0;
		}
		flag = 1;
		cnt = 1;
	}
	else ans += '.';
	for(int i = 1; i < st.size(); i++){
		if(i == st.size()-1) {
			if(st[i] != '.') cnt++;
			flag = 0;
			if(cnt % 2 == 1) {
				cout << -1;
				return 0;
			}
			else ans = check(ans, cnt);
			if(st[i] == '.') ans += '.';
		}
		else if(flag && st[i] == '.') {
			flag = 0;
			if(cnt % 2 == 1) {
				cout << -1;
				return 0;
			}
			else ans = check(ans, cnt);
			ans += '.';
			flag = 0;
			cnt = 0;
			continue;
		}
		else if(!flag && st[i] == '.') {
			ans += '.';
			continue;
		}
		flag = 1;
		cnt++;
	}
	cout << ans;
	return 0;
}

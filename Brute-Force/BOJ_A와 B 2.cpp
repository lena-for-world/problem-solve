#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0;
string obj;

// 백트래킹하여 시간을 줄임
// 더 긴 문자열에서 짧은 문자열을 만들 수 있는지 확인
void func(string st, int cnt) {
	if(cnt == obj.size()) {
		if(obj == st) ans = 1;
		return;
	}
	if(st[st.size()-1] == 'A') func(st.substr(0, st.size()-1), cnt-1);
	if(st[0] == 'B') {
		reverse(st.begin(), st.end());
		func(st.substr(0, st.size()-1), cnt-1);
	}
}

int main() {
	string s, t;
	cin >> s >> t;
	if(s.size() < t.size()) {
		obj = s;
		func( t, t.size());
	} else {
		ans = 0;
	}
	cout << ans;
	return 0;
}

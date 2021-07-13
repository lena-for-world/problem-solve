// 단순히 2중포문을 돌리면 O(NM)으로 시간초과가 발생
// KMP 알고리즘을 사용하여 O(N+M) 안에 해결

#include <iostream>
#include <vector>
using namespace std;

vector<int> make_can(string& st) {
	vector<int> res(st.size(), 0);
	for(int i = 1, j = 0; i < st.size() ; i++) {
		while(j > 0 && st[i] != st[j]) j = res[j-1];
		if(st[i] == st[j]) res[i] = ++j;
	}
	return res;
}

int main() {
	string s, t;
	cin >>s >> t;
	vector<int> can = make_can(t);
	int ssize = s.size();
	int tsize = t.size();
	for(int i = 0, j = 0; i < ssize; i++) {
		while(j > 0 && s[i] != t[j]) j = can[j-1];
		if(s[i] == t[j]) {
			if(j == tsize-1) {
				cout << 1;
				return 0;
			}
			else j++;
		}
	}
	cout << 0;
	return 0;
}

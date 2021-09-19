#include <iostream>
using namespace std;

int alp[26];

int main() {
	string s;
	int mx = -1;
	char ans;
	cin >> s;
	for(int i = 0; i< s.size(); i++){
		if(s[i] >= 97 && s[i] <= 122) s[i] -= 32;
		alp[s[i]-'A']++;
	}
	for(int i = 0 ; i < 26; i++) {
		if(mx == alp[i]) {
			ans = '?';
		}
		if((mx < alp[i]) && (alp[i] > 0)) {
			mx = alp[i];
			ans = i+'A';
		}
		
	}
	cout << ans;
	return 0;
}

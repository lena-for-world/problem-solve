#include <iostream>
using namespace std;

// 첫번째 문자열에서 겹치는 i를 먼저 찾고,
// 두번재 문자열에서 겹치는 j를 찾자
// for문을 돌면서 j인 c는 뛰어넘고 모두 .을 출력
// for문을 돌면서 i인 d는 뛰어넘고 모두 .출력
int main() {
	// your code goes here
	int a = 0, b, c = -1, d = -1;
	string s1, s2;
	cin >> s1 >> s2;
	for(int i = 0; i < s1.size(); i++) {
		for(int j = 0 ;j < s2.size(); j++) {
			if(s1[i] == s2[j]) {
				if(d== -1) {
					d = j;
				}
				if(c== -1) {
					c = i;
				}
			}
			
		}
	}
	for(int i = 0; i < s2.size(); i++) {
		if(i == d) {
			cout << s1 << '\n';
			a++;
			continue;
		}
		for(int j = 0 ;j < s1.size(); j++) {
			if(j == c) {
				cout << s2[a++];
				continue;
			}
			cout << ".";
		}
		cout << '\n';
	}
	return 0;
}

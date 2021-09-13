#include <iostream>
#include <string>
using namespace std;

int N;
int e = 0;
string answer;

bool isValid(string a) {
	int asize = a.size()/2;
	int idx = a.size()-1;
	// 홀수일 때도 맨 앞 1글자는 비교하지 않게 됨
	// 앞쪽은 검증 완료돼서 비교 안 해도 미중복 보장
	for(int i = 1; i <= asize; i++) {
		string s1 = a.substr(idx-i, i);
		string s2 = a.substr(idx, i);
		if(!s1.compare(s2)) return false;
		idx--;
	}
	return true;
}

void makeNumber(int n, string st) {
	if(e == 1) return;
	if(!isValid(st)) return;
	if(n == N) {
		e = 1;
		answer = st;
		return;
	}
	makeNumber(n+1, st +'1');
	makeNumber(n+1, st+'2');
	makeNumber(n+1, st+'3');
}

int main() {
	
	cin >> N;
	makeNumber(0, "");
	cout << answer;
	return 0;
}

#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int fail[MAX];

int main() {
	string t, p;
	getline(cin, t);
	getline(cin, p);
	int cnt = 0;
	vector<int> answer;
	// 실패 함수
	for(int i = 1, j = 0; i < p.size(); i++) {
		while(j > 0 && p[i] != p[j]) j = fail[j-1];
		if(p[i] == p[j]) fail[i] = ++j;
	}
	for(int i = 0, j = 0; i < t.size(); i++) {
		while(j > 0 && t[i] != p[j]) j = fail[j-1];
		if(t[i] == p[j]) {
			if(j == p.size()-1) {
				cnt++;
				answer.push_back(i-j+1);
				j = fail[j];
			} else ++j;
		}
	}
	cout << cnt << '\n';
	for(int a : answer) {
		cout << a << " ";
	}
	return 0;
}

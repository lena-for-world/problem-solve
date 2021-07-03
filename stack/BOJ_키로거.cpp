#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
  // 커서를 기준으로 양쪽을 2개의 스택에 분리하여 저장
	stack<int> frnt; stack<int> bck;
	string answer = "";
	string st = "";
	cin >> N;
	for(int i = 0; i <N; i++) {
		cin >> st;
		string answer = "";
		for(int j = 0; j < st.size(); j++) {
			if(st[j] == '<') {
				if(!frnt.empty()) {
					int temp = frnt.top(); frnt.pop();
					bck.push(temp);
				}
				else continue;
			}
			else if(st[j] == '>') {
				if(!bck.empty()) {
					int temp = bck.top(); bck.pop();
					frnt.push(temp);
				}
			}
			else if(st[j] == '-') {
				if(!frnt.empty()) {
					frnt.pop();
				}
			}
			else {
				frnt.push(st[j]);
			}
		}
		while(!frnt.empty()) {
			answer += frnt.top(); frnt.pop();
		}
		reverse(answer.begin(), answer.end());
		while(!bck.empty()) {
			answer += bck.top(); bck.pop();
		}
		cout << answer << '\n';
	}
	return 0;
}

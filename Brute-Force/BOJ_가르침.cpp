#include <iostream>
#include <vector>
using namespace std;

int alp[26];
int n, k, mx = 0;
vector<string> v;

void select(int cnt, int idx) {
	if(idx > 26) return;
  // 단어를 k개 골랐을 때
	if(cnt == k) {
		// 가능한 단어 개수 세기
		int cnt = 0;
		for(int i = 0; i < v.size(); i++) {
			int flag = 0;
			for(int j = 0; j < v[i].size(); j++) {
				if(!alp[v[i][j]-97]) {
					flag = 1;
					break;
				}
			}
			if(!flag) cnt++;
		}
		mx = max(cnt, mx);
		return;
	}
  // 선택하지 않은 알파벳이면 가르칠 단어로 포함해보기
  // 
	if(!alp[idx]) {
		alp[idx] = 1;
		select(cnt+1, idx+1);
		alp[idx] = 0;
	}
	select(cnt, idx+1);
}

int main() {
	cin >> n >> k;
	k -= 5;
	for(int i = 0; i < n; i++) {
		string st;
		cin >> st;
		v.push_back(st);
	}
	alp['a'-97] = 1, alp['n'-97] = 1, alp['t'-97] = 1;
	alp['i'-97] = 1, alp['c'-97] = 1;
	select(0, 0);
	cout << mx;
	return 0;
}

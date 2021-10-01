#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, t;
	cin >> n;
	string st;
	for(int i = 0; i < n; i++) {
		int shortest = 10001, longest = -1;
		vector<int> v[26];
		cin >> st >> t;
		for(int j = 0; j< st.size(); j++) {
			v[st[j]-'a'].push_back(j); // 문자가 등장하는 인덱스를 저장한다
		}
		for(int a = 0; a < 26; a++) {
			if(v[a].size() >= t) { // a~z까지 탐색하여 t번 이상 등장한 문자에 대해 k번을 포함하면서 가장 짧고 긴 문자를 찾는다
				if(t == 1) {
					shortest = longest = 1;
					break;
				}
				for(int b = 0; b < v[a].size(); b++) {
					if(b+t-1 < v[a].size()) shortest = min(v[a][b+t-1] - v[a][b], shortest);
				}
				for(int b = 0; b < v[a].size(); b++) {
					if(b+t-1 < v[a].size()) longest = max(v[a][b+t-1] - v[a][b], longest);
				}
			}
		}
		if(shortest == 1 && longest == 1) cout << 1 << " " << 1 << '\n';
		else if(shortest != 10001 && longest != -1) cout << shortest + 1 << " " << longest + 1 << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}

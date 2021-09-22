#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int checked[26], ans[26];

// 오름차순 정렬
bool cmp(pair<char, int> p1, pair<char, int> p2) {
	return p1.second > p2.second;
}

int main() {
	int n, cnt = 9, total = 0;
	vector<string> v;
	vector<pair<char, int>> res;
	map<char, int> m;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string st;
		cin >> st;
		v.push_back(st);
		int ten = 1;
        // 빈도 수 체크 (자릿수 고려)
		for(int a = st.size()-1; a >= 0; a--) {
			m[st[a]] += ten;
			ten *= 10;
		}
	}
	for(int i = 0; i < v.size(); i++) {
		for(int j = v[i].size()-1; j >= 0; j--) {
			res.push_back({v[i][j], m[v[i][j]]});
		}
	}
	sort(res.begin(), res.end(), cmp);
    // 그리디로 숫자 부여 (cnt)
	for(int i = 0; i < res.size(); i++) {
		int num = res[i].first-'A';
		if(!checked[num]) {
			checked[num] = 1;
			ans[num] = cnt;
			cnt--;
		}
	}
	for(int i = 0; i < v.size(); i++) {
		int ten = 1;
		int res = 0;
		for(int j = v[i].size()-1; j >= 0; j--) {
			res += (ans[v[i][j]-'A'] * ten);
			ten *= 10;
		}
		total += res;
	}
	cout << total;
	return 0;
}

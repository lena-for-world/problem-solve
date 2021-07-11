#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if(p1.first == p2.first) return p1.second < p2.second;
	return p1.first < p2.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, s, e, j = 0;
	cin >> N;
	vector<pair<int, int>> v, rooms;
	for(int a = 0; a < N; a++) {
		cin >> s >> e;
		v.push_back({s,e});
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < N; i++) {
		for(j = 0; j < rooms.size(); j++) {
			if(v[i].first < rooms[j].second) continue;
			else {
				rooms[j].second = v[i].second;
				break;
			}
		}
		if(j == rooms.size()) {
			rooms.push_back(v[i]);
		}
	}
	cout << rooms.size();
	return 0;
}

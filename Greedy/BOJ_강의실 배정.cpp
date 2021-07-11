3가지 방법으로 풀이 할 수 있다.

// (1) 우선순위 큐 이용

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if(p1.first == p2.first) return p1.second > p2.second;
		return p1.first > p2.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, s, e, cnt = 0, ans = 0;
	priority_queue<int, vector<int>, greater<int>> sq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	cin >> N;
	vector<pair<int, int>> v;
	for(int a = 0; a < N; a++) {
		cin >> s >> e;
		pq.push({s, e});
	}
	while(!pq.empty()) {
		pair<int, int> t = pq.top(); pq.pop();
		if(sq.empty()) sq.push(t.second);
		else {
			if(sq.top() <= t.first) {
				sq.pop(); sq.push(t.second);
			}
			else sq.push(t.second);
		}
	}
	cout << sq.size();
	return 0;
}


//(2) 갯수 단순 파악

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, s, e, cnt = 0, ans = 0;
	cin >> N;
	vector<pair<int, int>> v;
	for(int a = 0; a < N; a++) {
		cin >> s >> e;
		v.push_back({s,1});
		v.push_back({e,-1});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		cnt += v[i].second;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}

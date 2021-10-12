#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 위상 정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m;
	cin >> t;
	for(int a = 0; a < t; a++) {
		cin >> n >> m;
		vector<vector<int>> stu;
		vector<int> in, res, cost;
		stu.resize(n+1);
		in.resize(n+1, 0);
		res.resize(n+1, 0);
		cost.resize(n+1, 0);
		for(int i = 1; i <= n; i++) cin >> cost[i];
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			in[b]++;
			stu[a].push_back(b);
		}
		queue<int> q;
		for(int i = 1; i <= n; i++) {
			if(in[i] == 0) {
				q.push(i);
				res[i] = cost[i];
			}
		}
		while(!q.empty()) {
			int f = q.front();
			q.pop();
			for(int t : stu[f]) {
				if(--in[t] == 0) {
					q.push(t);
				}
				res[t] = max(res[t], res[f] + cost[t]);
			}
		}
		int w;
		cin >> w;
		cout << res[w] << '\n';
	}
	return 0;
}

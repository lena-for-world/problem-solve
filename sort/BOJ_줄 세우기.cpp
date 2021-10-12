#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> stu;
vector<int> in, res;

// 위상정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	stu.resize(n+1);
	in.resize(n+1, 0);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		in[b]++;
		stu[a].push_back(b);
	}
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(in[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		res.push_back(f);
		for(int t : stu[f]) {
			if(--in[t] == 0) q.push(t);
		}
	}
	for(int i = 0; i < n; i++) cout << res[i] << " ";
	return 0;
}

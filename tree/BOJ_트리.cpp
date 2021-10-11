#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int exist[501][501], visit[501];

void init() {
	for(int i = 0; i < 501; i++) {
		for(int j = 0; j < 501; j++) {
			exist[i][j] = 0;
		}
		visit[i] = 0;
	}
}

int main() {
	int n, m;
	int a, b;
	int total = 0;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		vector<vector<int>> child(n+1);
		int cnt = 0;
		init();
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			child[a].push_back(b);
			child[b].push_back(a);
			exist[a][b]++; exist[b][a]++;
		}
		for(int i = 1; i <= n; i++) {
			if(visit[i]) continue;
			int dupflag = 0, nodenum = 0, edges = 0; // 중복 간선 여부, 사이클 여부 판단
			queue<int> q;
			visit[i] = 1;
			q.push(i);
			while(!q.empty()) {
				int t = q.front(); q.pop();
				for(int a : child[t]) {
					edges++;
					if(exist[t][a] > 1 || exist[a][t] > 1) {
						dupflag = 1;
					}
					if(!visit[a]) {
						visit[a] = 1;
						q.push(a);
						nodenum++;
					}
				}
			}
      // (간선/2 != 노드 수 인 경우 사이클)
			if(!dupflag && (edges/2 == nodenum)) cnt++;
		}
		cout << "Case " << ++total << ": ";
		if(cnt == 0) cout << "No trees." << '\n';
		else if(cnt == 1) cout << "There is one tree." << '\n';
		else cout << "A forest of " << cnt << " trees." << '\n';
	}
	return 0;
}

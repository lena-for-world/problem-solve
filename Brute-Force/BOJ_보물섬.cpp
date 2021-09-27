#include <iostream>
#include <queue>
#include <vector>
#define MAX 98765432
using namespace std;

vector<string> map;
int visit[51][51];
int dist[51][51];
int n, m;
int diry[4] = {1,-1,0,0};
int dirx[4] = {0,0,1,-1};

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	visit[y][x] = 1;
	dist[y][x] = 0;
	int cnt = 0;
	q.push({y,x});
	while(!q.empty()) {
		int q1 = q.front().first; int q2 = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int ty = q1 + diry[i];
			int tx = q2 + dirx[i];
			if(ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
			if(!visit[ty][tx] && map[ty][tx] == 'L') {
				visit[ty][tx] = 1;
				if(dist[ty][tx] > dist[q1][q2] + 1) {
					dist[ty][tx] = dist[q1][q2] + 1;
					q.push({ty, tx});
					cnt = max(cnt, dist[ty][tx]);
				}
			}
		}
	}
	return cnt;
}

void init() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			visit[i][j] = 0;
			dist[i][j] = MAX;
		}
	}
}

int main() {
	int ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}
	init();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(map[i][j] == 'L') {
				init();
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

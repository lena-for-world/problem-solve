#include <iostream>
#include <iostream>
#include <queue>
using namespace std;

int dirx[4] = {1,0,-1,0};
int diry[4] = {0,1,0,-1};
int n, m, b, w;
string war[101];
int visit[101][101];

void bfs(pair<int, int> p, int team) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push(p);
	visit[p.first][p.second] = 1;
	while(!q.empty()) {
		pair<int, int> f = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int ty = f.first + diry[i];
			int tx = f.second + dirx[i];
			if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
				if(!visit[ty][tx] && (war[ty][tx] == team)) {
					visit[ty][tx] = 1;
					q.push({ty,tx});
					cnt++;
				}
			}
		}
	}
	if(team == 'B') b += (cnt * cnt);
	else w += (cnt*cnt);
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> war[i];
	}
	for(int i =0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(!visit[i][j]) {
				bfs({i, j}, war[i][j]);
			}
		}
	}
	cout << w << " " << b;
	return 0;
}

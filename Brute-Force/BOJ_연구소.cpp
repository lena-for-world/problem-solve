#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> cases;
int n, m;
int map[8][8];
int visited[8][8];
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};

// 0에 벽 3개를 세울 수 있는 모든 방법을 탐색
// 각 방법에서 bfs로 바이러스 감염을 진행시킨  바이러스에 감염되지 않은 방의 개수를 구한다

void infect(queue<pair<int, int>> q) {
	while(!q.empty()) {
		int f1 = q.front().first, f2 = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int tx = f1 + dirx[i];
			int ty = f2 + diry[i];
			if(tx >= 0 && tx < n && ty >= 0 && ty < m)  {
				if(!visited[tx][ty] && map[tx][ty] == 0) {
					visited[tx][ty] = 1;
					q.push({tx, ty});
				}
			}
		}
	}
}

int search() {
	int cnt = 0;
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visited[i][j] && map[i][j] == 2) {
				visited[i][j] = 1;
				q.push({i,j});
				infect(q);
			}
		}
	}
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			if(visited[i][j] == 0 && map[i][j] == 0)
				cnt++;
	return cnt;
}

void init() {
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			visited[i][j] = 0;
}

int main() {
	int mx = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(map[i][j] == 0) {
				cases.push_back({i,j});
			}
		}
	}
    // 벽 3개 세우는 모든 경우 완전 탐색
	for(int i = 0; i < cases.size(); i++) {
		map[cases[i].first][cases[i].second] = 1;
		for(int j = i +1; j < cases.size(); j++) {
			map[cases[j].first][cases[j].second] = 1;
			for(int k = j+1; k < cases.size(); k++) {
				map[cases[k].first][cases[k].second] = 1;
				mx = max(mx, search());
				init();
				map[cases[k].first][cases[k].second] = 0;
			}
			map[cases[j].first][cases[j].second] = 0;
		}
		map[cases[i].first][cases[i].second] = 0;
	}
	cout << mx;
	return 0;
}

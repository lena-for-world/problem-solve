#include <iostream>
#include <queue>
using namespace std;

int visit[101][101];
string map[101];
int diry[4] = {1,-1,0,0};
int dirx[4] = {0,0,1,-1};
int n;

void func(int y, int x, char col, bool rgcw) {
	queue<pair<int, int>> q;
	q.push({y,x});
	visit[y][x] = 1;
	while(!q.empty()) {
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int ny = ty + diry[i];
			int nx = tx + dirx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if(!rgcw) {
				if(visit[ny][nx] == 0 && map[ny][nx] == col) {
					visit[ny][nx] = 1;
					q.push({ny,nx});
				}
			} else {
				if(visit[ny][nx] == 0 && (col == 'R' || col == 'G')) {
					if(map[ny][nx] == 'R' || map[ny][nx] == 'G') {
						visit[ny][nx] = 1;
						q.push({ny,nx});
					}
				}
				if(visit[ny][nx] == 0 && map[ny][nx] == col) {
					visit[ny][nx] = 1;
					q.push({ny,nx});
				}
			}
		}
	}
}

void init() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < map[i].size(); j++) {
			visit[i][j] = 0;
		}
	}
}

int main() {
	int cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> map[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(visit[i][j] == 0) {
				func(i, j, map[i][j], false); // rgcw == false 적록색약 아닌 사람
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	init();
	cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < map[i].size(); j++) {
			if(visit[i][j] == 0) {
				func(i, j, map[i][j], true); // rgcw == 1 적록색약인 사람
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// bfs로 풀었지만... 빡구현 같은 느낌의 뿌요뿌요 문제!
// 데브매칭에 나옴

int visit[12][6];
int diry[4] = {1,-1,0,0};
int dirx[4] = {0,0,1,-1};

void init() {
	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < 6; j++) {
			visit[i][j] = 0;
		}
	}
}

int main() {
	int cnt = 0;
	string line;
	vector<string> puyo;
	bool flag = true;
	for(int i = 0; i < 12; i++) {
		cin >> line;
		puyo.push_back(line);
	}
	while(flag) {
		flag = false;
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j <12; j++) {
				int colcnt = 0;
				if(puyo[j][i] != '.') {
					init();
					char color = puyo[j][i];
					queue<pair<int, int>> q, tq;
					q.push({j, i});
					tq.push({j, i});
					visit[j][i] = 1;
					while(!q.empty()) {
						int f1 = q.front().first, f2 = q.front().second;
						q.pop();
						for(int a = 0; a < 4; a++) {
							int ny = f1 + diry[a];
							int nx = f2 + dirx[a];
							if(ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
							if((color == puyo[ny][nx]) && !visit[ny][nx]) {
								visit[ny][nx] = 1;
								q.push({ny,nx});
								tq.push({ny,nx});
								colcnt++;
							}
						}
					}
					if(tq.size() >= 4) {
						flag = true;
						while(!tq.empty()) {
							int f1 = tq.front().first, f2 = tq.front().second;
							tq.pop();
							puyo[f1][f2] = '.';
						}
					}
				}
			}
		}
		if(flag) cnt++;
		for(int i = 11; i >= 1; i--) {
			for(int j = 0; j < 6; j++) {
				if(puyo[i][j] == '.') {
					int ti = i-1;
					while(ti >= 0) {
						if(puyo[ti][j] != '.') {
							puyo[i][j] = puyo[ti][j];
							puyo[ti][j] = '.';
							break;
						}
						ti--;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}

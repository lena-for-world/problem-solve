#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int visit[101][101];
int check[101][101];
int dirx[4] = {1,0,-1,0};
int diry[4] = {0,-1,0,1};
int n;

void search(pair<int ,int> p) {
	queue<pair<int, int>> q;
	q.push(p);
	visit[p.first][p.second] = 1;
	while(!q.empty()) {
		int f1 = q.front().first; 
		int f2 = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = f1 + dirx[i];
			int ny = f2+ diry[i];
			if(nx >=0 && nx < n && ny >=0 && ny < n) {
				if(visit[nx][ny] == 0 && check[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
		}
	}
}

void find(int height) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(map[i][j] <= height) check[i][j] = 1;
		}
	}
}

void init() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			visit[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

int main() {
	int highest = 0, mx = 0, cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
			highest = max(highest, map[i][j]);
		}
	}
    // 아무 지역도 물에 잠기지 않을 수 있으므로 0부터 탐색
	for(int i = 0; i <= highest; i++) {
		find(i); // i 이하의 높이를 가져서 가라앉는 지역들 체크
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(visit[i][j] == 0 && (check[i][j] == 0)) {
					search({i,j});
					cnt++;
				}
			}
		}
		init();
		mx = max(cnt, mx);
		cnt = 0;
	}
	cout << mx;
	return 0;
}

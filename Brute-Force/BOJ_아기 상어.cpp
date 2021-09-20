#include <iostream>
#include <queue>
#include <cmath>
#define MAX 98765432;
using namespace std;

int n;
int map[21][21];
int ssize = 2;
int diry[4] = {1,0,0,-1};
int dirx[4] = {0,-1,1,0};
int check[21][21];
int route[21][21];

struct compare {
	bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
		if(p1.first == p2.first) {
			if(p1.second.first == p2.second.first) return p1.second.second > p2.second.second;
			return p1.second.first > p2.second.first;
		}
		return p1.first < p2.first;
	}
};

int bfs(pair<int, int> fish, pair<int, int> shark) {
	int cnt = 0;
	queue<pair<int, int>> q; // queue 초기화
	q.push(shark);
	check[shark.first][shark.second] = 1;
	route[shark.first][shark.second] = 0;
	while(!q.empty()) {
		int y = q.front().first; int x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int ty = y + diry[i];
			int tx = x + dirx[i];
			if(ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
			if(fish.first == ty && fish.second == tx) {
				// 물고기 위치를 만남 물고기는 항상 상어보다 작으니까 체크 안해도 됨
				return route[y][x]+1;
			}
			if(check[ty][tx] == 0 && map[ty][tx] <= ssize) {
				q.push({ty,tx});
				check[ty][tx] = 1;
				route[ty][tx] = min(route[ty][tx], route[y][x] + 1);
			}
		}
	}
	return -1;
}

void init() {
	for(int i = 0;i < n; i++) { 
		for(int j = 0; j <n; j++) {
			check[i][j] = 0;
			route[i][j] = MAX;
		}
	}
}

int calc(pair<int, int> fish, pair<int, int> shark) {
	// shark 위치부터 fish까지 갈 수 있는지 보기
	init();
	// 상어가 물고기 위치로 갈 수 없으면 -1 리턴
	int res = bfs(fish, shark);
	if(res == -1) return -1;
	else return res;
	
}



int main() {
	pair<int, int> shark;
	int totalTime = 0, fishCount = 0;
	cin >> n;
	for(int i = 0;i < n; i++) { 
		for(int j = 0; j <n; j++) {
			cin >> map[i][j];
			if(map[i][j] == 9) shark = {i,j};
		}
	}
	while(1) {
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
        // 상어가 있는 좌표는 빼고 
				if(map[i][j] > 0 && map[i][j] < ssize && (map[i][j] != 9)) {
          // 먹을 수 있는 물고기에게 이동할 수 있는지 판단
					int res = calc({i,j}, shark);
					if(res == -1) continue;
					else pq.push({-res, {i,j}}); // 물고기 좌표와 이동거리 저장
				}
			}
		}
		if(pq.empty()) break;
		int newy = pq.top().second.first;
		int newx = pq.top().second.second;
		totalTime -= pq.top().first;
		fishCount++;
	//	cout << newy << " " << newx << " " << ssize << " " << totalTime <<endl;
		// 상어 크기만큼 물고기를 먹었다면 상어 크기 +1
		if(fishCount == ssize) {
			ssize++;
			fishCount = 0;
		}
		map[newy][newx] = 9;
		map[shark.first][shark.second] = 0;
		shark = {newy, newx};
	}
	cout << totalTime;
	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 987654321
using namespace std;

int city[51][51];
int visited[13];
int res = MAX, N, M;
vector<pair<int, int>> house, store;

int calc(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

void dfs(int which, int temp) {
	if(temp == M) {
		int total = 0;
		// 최대 선택가능한 개수 도달, 각 집으로부터 치킨집의 거리 계산
		for(int i = 0; i < house.size(); i++) {
			int tempmn = MAX;
			for(int j = 0; j < store.size(); j++) {
				if(visited[j]) {
					tempmn = min(tempmn, calc(house[i], store[j]));
				}
			}
			total += tempmn;
		}
		res = min(total, res);
		return;
	}
	if(which == store.size()) return;
	visited[which] = 1;
	dfs(which+1, temp+1);
	visited[which]= 0;
	dfs(which+1, temp);
}

int main() {
   cin >> N >> M;
   for(int i = 1; i<= N; i++) {
      for(int j = 1; j <= N; j++ ){
         cin >> city[i][j];
         if(city[i][j] == 1) {
            house.push_back({i,j});
         } else if(city[i][j] == 2) {
            store.push_back({i,j});
         }
      }
   }
   dfs(0, 0); // 치킨집을 선택하거나 선택하지 않거나로 완전탐색
   cout << res;
   return 0;
}

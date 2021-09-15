#include <iostream>
#include <queue>
using namespace std;

int res[1001][1001];
int map[1001][1001];
int check[1001][1001];
int dirx[2] = {1, 0};
int diry[2] = {0, 1};

int main() {
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n;i++) {
		for(int j = 1 ; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> q;
	q.push({1,1});
	res[1][1] = map[1][1];
	while(!q.empty()) {
		int f1 = q.front().first; int f2 = q.front().second;
		q.pop();
		for(int i = 0; i < 2; i++) {
			int tx = f1 + dirx[i];
			int ty = f2 + diry[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
				if(!check[tx][ty]) {
					check[tx][ty] = 1;
					res[tx][ty] = res[f1][f2] + map[tx][ty];
					q.push({tx, ty});
				}
				else if(res[tx][ty] < res[f1][f2] + map[tx][ty]) {
					res[tx][ty] = res[f1][f2] + map[tx][ty];
					q.push({tx, ty});
				}
			}
		}
	}
	cout << res[n][m];
	return 0;
}

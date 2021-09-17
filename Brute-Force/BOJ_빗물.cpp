#include <iostream>
using namespace std;

int world[501][501];

int main() {
	int h, w, a; // h == 행 w == 열
	int sum = 0;
	cin >> h >> w;
	for(int i = 0; i < w; i++) {
		cin >> a;
		for(int j = h-1; j >= h-a; j--) {
			world[j][i] = 1; // 벽만들기
		}
	}
	for(int i = 0; i < h; i++) {
		int flag = 0, cnt = 0;
		for(int j = 0; j < w; j++) {
			if(!flag && world[i][j]) {
				flag = 1;
				continue;
			}
			if(flag && world[i][j]) {
				sum += cnt;
				cnt = 0;
			}
			if(flag && (world[i][j] == 0)) {
				cnt++;
			}
		}
	}
	cout << sum;
	return 0;
}

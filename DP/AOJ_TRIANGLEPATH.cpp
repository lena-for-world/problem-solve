#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cache[101][101], triangle[101][101];

int calcMax(int y, int x) {
	if(y == n-1) return triangle[y][x];
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	return ret = max(calcMax(y+1, x), calcMax(y+1, x+1)) + triangle[y][x];
}

void init() {
	for(int i = 0; i < 101; i++) {
		for(int j = 0; j < 101; j++) {
			cache[i][j] = -1;
			triangle[i][j] = 0;
		}
	}
}

int main() {
	int t, a;
	cin >> t;
	for(int i = 0;i < t; i++) {
		cin >> n;
		init();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= i; j++) {
				cin >> a;
				triangle[i][j] = a;
			}
		}
		cout << calcMax(0,0) << '\n';
	}
	return 0;
}

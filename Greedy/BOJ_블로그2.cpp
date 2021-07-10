#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int red = 0, blue = 0;
	string color;
	cin >> N >> color;
	char col = 'A';
	for(int i = 0; i < color.size(); i++) {
		if(color[i] == col) continue;
		else {
			col = color[i];
			if(color[i] == 'R') red++;
			else blue++;
		}
	}
	if(red == N || blue == N) cout << 1;
	else {
		int ans = min(red, blue);
		cout << ans + 1;
	}
	return 0;
}

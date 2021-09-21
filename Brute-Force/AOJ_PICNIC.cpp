#include <iostream>
using namespace std;

int n;
bool pairing[10][10];
bool taken[10];

int countPairings() {
	int ret = 0;
	int firstMeet = -1;
	for(int i = 0; i < n; i++) {
		if(!taken[i]) {
			firstMeet = i;
			break;
		}
	}
	if(firstMeet == -1) return 1;
	for(int i = firstMeet+1; i < n; i++) {
		if(!taken[i] && pairing[firstMeet][i] == 1) {
			taken[firstMeet] = taken[i] = true;
			ret += countPairings();
			taken[firstMeet] = taken[i] = false;
		}
	}
	return ret;
}

void init() {
	for(int i = 0; i< 10; i++){
		for(int j = 0; j < 10; j++) {
			pairing[i][j] = 0;
		}
	}
	for(int i = 0; i< 10; i++) taken[i] = 0;
}

int main() {
	int t, m;
	cin >> t;
	for(int q = 0; q < t; q++) {
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			pairing[a][b] = pairing[b][a] = 1;
		}
		cout << countPairings() << '\n';
		init();
	}
	return 0;
}

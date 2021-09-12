#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 완탐 너무 못한다 정말 이게 실번데 ㅋㅋㅋ

int main() {
	int n, mn = 3000;
	int score[20][20];
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> score[i][j];
		}
	}
	for(int i = 1; i < (1 << n); i++) {
		int cnt = 0;
		vector<int> first, second;
		for(int j = 0; j < n; j++) {
			if( (i & ( 1 << j )) != 0 ) cnt++;
		}
		if(cnt!=n/2) continue;
		for(int b = 0; b < n; b++) {
			if((i & ( 1 << b )) == 0) first.push_back(b);
			else second.push_back(b);
		}
		int s1 = 0, s2 = 0;
		for(int a = 0; a < n/2; a++) {
			for(int b = 0; b < n/2; b++) {
				s1 += score[first[a]][first[b]];
				s2 += score[second[a]][second[b]];
			}
		}
		if(mn > abs(s1-s2)) {
			mn = abs(s1-s2);
		}
	}
	cout << mn;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int n;
string st[50];

int search(int mx) {
	for(int i = 0; i < n; i++) {
		int cnt = 1;
		for(int j = 1; j < n; j++) {
			if(st[i][j-1] == st[i][j]) {
				cnt++;
			} else {
				cnt = 1;
			}
			mx = max(mx, cnt);
		}
	}
	for(int i = 0; i < n; i++) {
		int cnt = 1;
		for(int j = 1; j < n; j++) {
			if(st[j-1][i] == st[j][i]) {
				cnt++;
			} else {
				cnt = 1;
			}
			mx=max(mx, cnt);
		}
	}
	return mx;
}

int main() {
	int mx;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> st[i];
	}
	
	mx = search(-2);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < st[i].size(); j++) {
			if(j+1 < st[i].size() && (st[i][j] != st[i][j+1])) {
				swap(st[i][j], st[i][j+1]);
				mx = max(mx, search(mx));
				swap(st[i][j], st[i][j+1]);
			}
			if(i+1 < n && (st[i][j] != st[i+1][j])) {
				swap(st[i][j], st[i+1][j]);
				mx = max(mx, search(mx));
				swap(st[i][j], st[i+1][j]);
			}
		}
	}
	
	cout << mx;
	return 0;
}

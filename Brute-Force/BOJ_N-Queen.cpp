#include <iostream>
#include <cmath>
using namespace std;

int n, ans = 0;
int col[16];

int promising(int idx) {
	for(int i = 0; i< idx; i++) {
		if(col[i] == col[idx]) return 0;
		if(idx-i == abs(col[idx] - col[i])) return 0;
	}
	return 1;
}

void func(int cnt) {
	if(cnt == n) {
		ans++;
		return;
	}
	for(int i = 0; i < n; i++) {
		col[cnt] = i;
		if(promising(cnt)) {
			func(cnt+1);
		}
	}
}

int main() {
	cin >> n;
	func(0);
	cout << ans;
	return 0;
}

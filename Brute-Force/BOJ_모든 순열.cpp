#include <iostream>
using namespace std;

int n;
int check[8];
int idx[8];

void backtrack(int cnt) {
	if(cnt == n) {
		for(int i = 0; i < n; i++) {
			cout << idx[i] << " ";
		}
		cout << '\n';
		return;
	}
	for(int i = 0; i < n; i++) {
		if(!check[i]) {
			check[i] = 1;
			idx[cnt] = i+1;
			backtrack(cnt+1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	backtrack(0);
	return 0;
}

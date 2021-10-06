#include <iostream>
using namespace std;

int main() {
	int G, W, H, ans = 0;
	cin  >> G;
	W = H = 1;
	while(1) {
		if(W-1 == H && W*W - H*H > G) break;
		if(W*W - H*H > G) {
			H++;
			continue;
		}
		if(W*W - H*H == G) {
			cout << W << '\n';
			ans++;
		}
		W++;
	}
	if(ans == 0) cout << -1;
	return 0;
}

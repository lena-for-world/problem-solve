#include <iostream>
using namespace std;

int cache[1001][1001];

int calc(int n, int k) {
	if(n < k || k < 0) return 0;
	if(n == 0 && k == 0) return 1;
	int& ret = cache[n][k];
	if(ret != -1) return ret;
	ret = calc(n-1, k) + calc(n-1, k-1);
	return ret % 10007;
}

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < 1001; i++) {
		for(int h = 0; h < 1001; h++) {
			cache[i][h] = -1;
		}
	}
	cout << calc(n, k);
	return 0;
}

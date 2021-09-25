#include <iostream>
#include <vector>
#define MAX 98765432
using namespace std;

int cost[1200];
int c, n, ans = MAX;
vector<pair<int, int>> v;

int main() {
	cin >> c >> n;
	for(int i = 1; i < 1200; i++) cost[i] = MAX;
	for(int i = 0; i < n ;i++) {
		int a, b;
		cin >> a >> b;
		cost[b] = min(cost[b], a);
	}
	for(int i = 1; i < 1200; i++) {
		for(int j = 0; j <= i; j++) {
			cost[i] = min(cost[i], cost[j] + cost[i-j]);
		}
	}
	for(int i = c; i < 1200; i++) {
		ans = min(ans, cost[i]);
	}
	cout << ans;
	return 0;
}

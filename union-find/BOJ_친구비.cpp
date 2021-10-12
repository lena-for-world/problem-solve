#include <iostream>
#include <vector>
using namespace std;

vector<int> p, cost;

int find(int n) {
	if(p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if(t1 > 0 && (t1 == t2)) return;
	
	if(cost[t1] > cost[t2]) {
		p[t2] = t1;
		cost[t2] = cost[t1];
	} else {
		p[t1] = t2;
		cost[t1] = cost[t2];
	}
}

int main() {
	int n, m, k, sum = 0;
	cin >> n >> m >> k;
	p.resize(n+1, -1);
	cost.resize(n+1, -1);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cost[i+1] = -a;
	}
	for(int i = 0 ; i < m; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	for(int i = 1; i <= n; i++) {
		if(p[i] < 0) sum += cost[i];
	}
	if(-sum <= k) cout << -sum;
	else cout << "Oh no";
	return 0;
}

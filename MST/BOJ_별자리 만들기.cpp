#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<double> x, y;
vector<int> p;
vector<pair<double, pair<int, int>>> edges;

int find(int n) {
	if(p[n] < 0) return n;
	return p[n] = find(p[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != -1 && a == b) return false;
	p[a] = b;
	return true;
}

int main() {
	int n;
	double ans = 0;
	cin >> n;
	p.resize(n+1, -1);
	for(int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			double xx = x[i]-x[j];
			double yy = y[i]-y[j];
			double temp = sqrt(xx*xx + yy*yy);
			edges.push_back({temp, {i+1, j+1}});
		}
	}
	sort(edges.begin(), edges.end());
	for(int i = 0; i < edges.size(); i++) {
		int tx = edges[i].second.first;
		int ty = edges[i].second.second;
		if(merge(tx, ty)) {
			ans += edges[i].first;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m, ans = 2000000001;

int main() {
	cin >> n >> m;
	for(int i =0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int i = 0, j =0;
	sort(v.begin(), v.end());
	while(1) {
		if(i == n && j != n) {
			while(j < n) {
				if(abs(v[i-1] - v[j]) >= m)
					ans = min(ans, abs(v[i-1] - v[j]));
				j++;
			}
			break;
		}
		if(i != n && j == n) {
			while(i < n) {
				if(abs(v[i] - v[j-1]) >= m)
					ans = min(ans, abs(v[i] - v[j-1]));
				i++;
			}
			break;
		}
		if(abs(v[i] - v[j]) >= m) {
			ans = min(ans, abs(v[i] - v[j]));
			j++;
		} else {
			i++;
	 }
	}
	cout << ans;
	return 0;
}

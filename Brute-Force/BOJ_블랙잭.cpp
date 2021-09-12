#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,m,t;
	int sum = 0, mn = 600000, answer = 0;
	vector<int> v;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			for(int a = j+1; a < n; a++) {
				int sum = v[i] + v[j] + v[a];
				if(mn > m-sum && m >= sum) {
					mn = m - sum;
					answer = sum;
				}
			}
		}
	}
	cout << answer;
	return 0;
}

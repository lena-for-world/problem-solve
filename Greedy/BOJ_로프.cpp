#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, ans = 0;
	vector<int> v;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		int cnt = (v.size()-i);
		ans = max(v[i] * cnt, ans);
	}
	cout << ans;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, a;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> x;
	sort(v.begin(), v.end()); // 맨 앞, 맨 뒤 각각에서 출발하여 좁혀들어가기 위해 
	int i = 0, j = v.size()-1, cnt = 0;
	while(i < j) {
		int sum = v[i] + v[j];
		if(sum >= x) {
			if(sum == x) cnt++;
			j--;
		} else {
			i++;
		}
	}
	cout << cnt;
	return 0;
}

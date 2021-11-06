#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int n, k, cnt;
	cin >> n >> k;
	for(int i = 0; i < n; i++) q.push(i+1);
	cout << '<';
	cnt = 0;
	while(!q.empty()) {
		if(cnt+1 == k) {
			cout << q.front();
			if(q.size() != 1) cout << ", ";
			q.pop();
			cnt = 0;
		} else {
			cnt++;
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	cout << '>';
	return 0;
}

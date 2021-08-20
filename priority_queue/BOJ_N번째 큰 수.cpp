
위는 328ms, 아래는 484ms 걸리는 코드

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, a;
	cin >> N;
	priority_queue<int, vector<int>> pq;
	for(int i = 0; i < N; i++) {
		cin >> a;
		pq.push(-a);
	}
	for(int i = 0; i < N*N - N; i++) {
		int top = -pq.top();
		cin >> a;
		if(top < a) {
			pq.pop();
			pq.push(-a);
		}
	}
	cout << -pq.top();
	return 0;
}


#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, a;
	cin >> N;
	priority_queue<int, vector<int>> pq;
	for(int i = 0; i < N; i++) {
		cin >> a;
		pq.push(-a);
	}
	for(int i = 0; i < N*N - N; i++) {
		int top = -pq.top();
		cin >> a;
		if(top < a) {
			pq.pop();
			pq.push(-a);
		}
	}
	cout << -pq.top();
	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> build[501];
vector<int> hour(501);
vector<int> res(501);
vector<int> indegree(501);

int main() {
	int N, a;
	cin >> N;
	int j = 0;
	for(int i = 0; i < N; i++) {
		j =0;
		while(cin >> a) {
			if(a == -1) break;
			if(j == 0) {
				hour[i] = a;
			}
			else {
				indegree[i]++;
				build[a-1].push_back(i);
			}
			j++;
		}
	}
	queue<int> q;
	for(int i = 0; i < N; i++)
		if(indegree[i] == 0) {
			q.push(i);
			res[i] = hour[i];
		}
	for(int i = 0; i < N; i++) {
		if(q.empty()) return 0;
		int temp = q.front();
		q.pop();
		for(int c : build[temp]) {
			if(--indegree[c] == 0) q.push(c);
			res[c] = max(res[c], hour[c] + res[temp]);
		}
	}
	for(int i = 0; i < N; i++) cout << res[i] << '\n';
	return 0;
}

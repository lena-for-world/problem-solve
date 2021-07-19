#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 위상 정렬

vector<int> indegree(1001, 0);
vector<int> result;
vector<int> adj[1001];

int main() {
	int N, M, f, t, num;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> num >> f;
		for(int j = 1; j < num; j++) {
			cin >> t;
			indegree[t-1]++;
			adj[f-1].push_back(t-1);
			f = t;
		}
	}
	queue<int> q;
	for(int i = 0; i < N; i++) if(indegree[i] == 0) q.push(i);
	for(int i = 0; i < N; i++) {
		if(q.empty()) {
			cout << 0;
			return 0;
		}
		int temp = q.front();
		q.pop();
		result.push_back(temp+1);
		for(int next : adj[temp]) {
			--indegree[next];
			if(indegree[next] == 0) q.push(next);
		}
	}
	for(int i = 0; i < result.size(); i++) cout << result[i] << '\n';
	return 0;
}

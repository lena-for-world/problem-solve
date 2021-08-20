#include <iostream>
#include <vector>
#include <queue>
#define MAX 32000
using namespace std;
vector<int> edge[MAX];
int indegree[MAX];
vector<int> answer;


int main() {
	int N, M, a, b;
	cin >> N >> M;
	for(int i = 0 ;i < M; i++) {
		cin>> a >> b;
		edge[a].push_back(b);
		indegree[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i <= N; i++) {
		if(indegree[i] == 0) {
			pq.push(i);
		}
	}
	for(int i = 1; i <= N; i++) {
		int now = pq.top();
		pq.pop();
		answer.push_back(now);
		for(int j : edge[now]) {
			if(--indegree[j] == 0) pq.push(j);
		}
	}
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}

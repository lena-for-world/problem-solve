#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 98765432;
const int MAX = 20000;
vector<pair<int, int>> adj[MAX];
int dist[MAX];
int visited[MAX];

int main() {
	int V, E, K;
	int u, v, w;
	cin >> V >> E >> K;
	for(int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u-1].push_back({v-1,w});
	}
	// 간선 가중치가 작은 친구부터 탐색하도록 greater로 pq 설정
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 0; i < MAX; i++) dist[i] = INF;
	dist[K-1] = 0;
	pq.push({0,K-1});
	while(!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while(!pq.empty() && visited[curr]);
		if(visited[curr]) break; // pq가 비었다는 뜻 == 더이상 탐색할 정점이 없음
		visited[curr] = 1;
		for(auto &p : adj[curr]) {
			int next = p.first; int weight = p.second;
			if(dist[next] > dist[curr] + weight) {
				dist[next] = dist[curr] + weight;
				pq.push({dist[next], next});
			}
		}
	}
	
	for(int i = 0; i < V; i++) {
		if(dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}

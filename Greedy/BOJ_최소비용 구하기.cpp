#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
#define INF 987654321
using namespace std;

vector<pair<int, int>> adj[MAX];
int visited[MAX];
int dist[MAX];

int main() {
	int N, M, a, b, c, F, T;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a-1].push_back({b-1, c});
	}
	cin >> F >> T;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 0; i < N; i++) dist[i] = INF;
	dist[F-1] = 0;
	pq.push({0, F-1});
	while(!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while(!pq.empty() && visited[curr]);
		if(visited[curr] == 1) break;
		visited[curr] = 1;
		for(auto &p : adj[curr]) {
			int next = p.first; int w = p.second;
			if(dist[next] > dist[curr] + w) {
				dist[next] = dist[curr] + w;
				pq.push({dist[next], next});
			}
		}
	}
	cout << dist[T-1];
	return 0;
}

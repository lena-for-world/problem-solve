#include <iostream>
#include <queue>
#include <vector>
#define MAX 800
#define INF 987654321
using namespace std;

vector<pair<int, int>> adj[MAX];
int dist[MAX];

void Dijkstra(int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[n] = 0;
	pq.push({0, n});
	while(!pq.empty()) {
		int curr = pq.top().second;
		pq.pop();
		for(auto& p : adj[curr]) {
			int next = p.first; int w = p.second;
			if(dist[next] > dist[curr] + w) {
				dist[next] = dist[curr] + w;
				pq.push({dist[next], next});
			}
		}
	}
}

// 1->a->b->n
// 1->b->a->n
int main() {
	int N, E, a, b, c, V1, V2;
	int answer;
	cin >> N >> E;
	for(int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a-1].push_back({b-1, c});
		adj[b-1].push_back({a-1, c});
	}
	cin >> V1 >> V2;
	V1 -= 1; V2 -= 1;
	bool one = true, two= true;
	
	for(int i = 0; i < MAX; i++) dist[i] = INF;
	Dijkstra(0);
	int route1 = dist[V1];
	int route2 = dist[V2];
	if(route1 == INF) one = false;
	if(route2 == INF) two = false;
	
	for(int i = 0; i < MAX; i++) dist[i] = INF;
	Dijkstra(V1);
	if(one == true) route1 += dist[V2];
	if(two == true) route2 += dist[V2];
	
	for(int i = 0; i < MAX; i++) dist[i] = INF;
	Dijkstra(V2);
	if(one == true) route1 += dist[N-1];
	
	for(int i = 0; i < MAX; i++) dist[i] = INF;
	Dijkstra(V1);
	if(two == true) route2 += dist[N-1];
	
	if(!one && !two) {
		answer =  -1;
	} else {
		answer = min(route1, route2);
	}
	
	if(answer == INF) {
		cout << -1;
	} else {
		cout << answer;
	}
	return 0;
}

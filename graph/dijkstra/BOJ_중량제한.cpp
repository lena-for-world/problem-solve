#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 2000000000
using namespace std;

vector<pair<int, int>> nodes[10001];
int dist[10001];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({c, b});
		nodes[b].push_back({c, a});
	}
	memset(dist, 0, sizeof(dist));
	int start, end;
	priority_queue<pair<int, int>> pq;
	cin >> start >> end;
	dist[start] = INF;
	// {중량제한, 노드번호}
	pq.push({INF, start});
	while(!pq.empty()) {
		int w = pq.top().first, node = pq.top().second;
		pq.pop();
		if(dist[node] > w) continue; // w 보다 큰 경우는 고려하지 않음. 어차피 w까지 밖에 
		for(pair<int, int> t : nodes[node]) {
			int cost = min(t.first, w);
			int next = t.second;
			if(dist[next] < cost) {
				dist[next] = cost;
				pq.push({dist[next], next});
			}
		}
	}
	cout << dist[end];
	return 0;
}

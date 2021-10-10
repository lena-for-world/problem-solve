#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dist[101], visit[101];

int main() {
	int n, m;
	int ans = INF, person;
	vector<int> v[101];
	cin >> n >> m;
	for(int i = 0 ;i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int j = 1; j <= n; j++) {
		for(int i = 1; i <= n; i++ ){
			dist[i] = INF;
			visit[i] = 0;
		}
		priority_queue<pair<int, int>> pq;
		dist[j] = 0;
		pq.push({-dist[j], j});
		while(!pq.empty()) {
			int curr;
			do {
				curr = pq.top().second;
				pq.pop();
			} while(!pq.empty() && visit[curr]);
			if(visit[curr] == 1) break;
			visit[curr] = 1;
			for(int p : v[curr]) {
				if(visit[p]) continue;
				if(dist[p] > dist[curr] + 1) {
					dist[p] = dist[curr] + 1;
					pq.push({-dist[p], p});
				}
			}
		}
		int temp = 0;
		for(int i = 1; i <= n; i++) {
			temp += dist[i];
		}
		if(ans == INF || ans > temp) {
			ans = temp;
			person = j;
		}
	}
	cout << person;
	return 0;
}

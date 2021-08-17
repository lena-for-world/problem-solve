#include <iostream>
#include <vector>
#define MAX 500
#define INF 987654321
using namespace std;
vector<pair<int, int>> adj[MAX];
long long dist[MAX]; // 음의 사이클이 생성되는 최악의 경우 21억을 넘어갈 가능성이 있기 때문에 long long으로 자료형 지정

int main() {
	int N, M;
	int a, b, c;
	int flag = 0;
	cin >> N >> M;
	for(int i = 0; i < M; i++ ){
		cin >> a >> b >> c;
		adj[a-1].push_back({b-1, c});
	}
	for(int i = 0;i < N; i++) dist[i] = INF;
	dist[0] = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(auto &p : adj[j]) {
				int next = p.first; int w = p.second;
				if(dist[j] != INF && dist[next] > dist[j] + w) {
					dist[next] = dist[j] + w;
          // N번째 루프에 값이 갱신되면 음의 싸이클이 존재한다.
					if(i == N-1) flag = 1;
				}
			}
		}
	}
	if(flag) {
		cout << -1;
	} else {
		for(int i = 1; i < N; i++) {
			if(dist[i] == INF) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
	return 0;
}

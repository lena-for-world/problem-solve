#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n, k, s;
int dist[401][401];
vector<int> v[401];

void floyd() {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() {
  // 시간초과 방지를 위해 꼭 넣어주기
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for(int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}
	floyd();
	cin >> s;
	for(int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		if(dist[a][b] != INF) cout << -1 << '\n';
		else if(dist[b][a] != INF) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}

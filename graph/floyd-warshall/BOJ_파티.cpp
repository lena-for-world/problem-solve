#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n, k, x;
int dist[1001][1001];
vector<int> v[1001];

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> x;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for(int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	floyd();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dist[i][x] + dist[x][i]);
	}
	cout << ans << '\n';
	return 0;
}

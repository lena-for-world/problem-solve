#include <iostream>
#define INF 987654321
#define MAX 100
using namespace std;

int dist[MAX][MAX];

int main() {
	int N, M;
	int a, b, c;
	cin >> N >> M;
	for(int i = 0;i < N; i++) {
		for(int j = 0; j < N; j++ ){
			dist[i][j] = INF;
		}
	}
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		dist[a-1][b-1] = min(dist[a-1][b-1], c);
	}
	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for(int i = 0;i < N; i++) {
		for(int j = 0; j < N; j++ ){
			if(dist[i][j] ==INF) cout << 0 << " ";
			else if(i == j) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}

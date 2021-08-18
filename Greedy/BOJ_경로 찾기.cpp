#include <iostream>
#define INF 987654321
#define MAX 100
using namespace std;

int dist[MAX][MAX];

int main() {
	int M;
	int a;
	cin >> M;
	for(int i = 0;i < M; i++) {
		for(int j = 0; j < M; j++ ){
			cin >> a;
			dist[i][j] = a;
		}
	}
	for(int k = 0; k < M; k++) {
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < M; j++) {
				if(dist[i][k] + dist[k][j] == 2) dist[i][j] = 1;
			}
		}
	}
	
	for(int i = 0;i < M; i++) {
		for(int j = 0; j < M; j++ ){
			if(dist[i][j] ==0) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}

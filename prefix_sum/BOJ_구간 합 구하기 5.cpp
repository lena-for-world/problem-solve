#include <iostream>
using namespace std;

int sum[1110][1110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, a;
	int x1, y1, x2, y2;
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> a;
			sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + a;
		}
	}
	for(int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
	}
	return 0;
}

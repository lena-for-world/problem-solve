#include <iostream>
#include <vector>
using namespace std;

int sum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	int a, t;
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> t;
		sum[i] = sum[i-1] + t;
	}
	for(int i = 0; i < M; i++) {
		cin >> a >> t;
		cout << sum[t] - sum[a-1] << '\n';
	}
	return 0;
}

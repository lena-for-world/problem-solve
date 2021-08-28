
#include <iostream>
using namespace std;

long long sum[4000400];
long long num[4000400];
int N;

long long init(int node, int start, int end) {
	if(start == end) return sum[node] = num[start];
	int mid = (start + end) / 2;
	return sum[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}

void update(int node, int start, int end, int idx, long long diff) {
	if(start > idx || end < idx) return;
	sum[node] += diff;
	if(start == end) return;
	int mid = (start+ end) / 2;
	update(node*2, start, mid, idx, diff);
	update(node*2+1, mid+1, end, idx, diff);
}

long long calc(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return sum[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return calc(L, R, nodeNum * 2, nodeL, mid) + calc(L, R, nodeNum*2+1, mid+1, nodeR);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, K, a, b;
	long long c;
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	init(1, 1, N);
	for(int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if(a == 1) {
			update(1, 1, N, b, c-num[b]);
			num[b] = c;
		} else if(a == 2){
			cout << calc(b, c, 1, 1, N) << '\n';
		} else {
			continue;
		}
	}
	return 0;
}

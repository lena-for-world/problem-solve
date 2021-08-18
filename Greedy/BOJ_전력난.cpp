// 최소 스패닝 트리(MST) - 크루스칼 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200000
using namespace std;

int uf[MAX];

int find(int n) {
	if(uf[n] < 0) return n;
	return uf[n] = find(uf[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return false;
	uf[b] = a;
	return true;
}

int main() {
	int N, M;
	int a, b, c;
	while(cin >> N && cin >> M) {
		if(!N && !M) break;
		vector<pair<int, pair<int, int>>> edge;
		int total = 0, cnt = 0, totalcost = 0;
		for(int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			edge.push_back({c, {a, b}});
			totalcost += c;
		}
		sort(edge.begin(), edge.end());
		for(int i = 0; i < N; i++) uf[i] = -1;
		for(int i = 0; i < M; i++) {
			if(cnt == N-1) break;
			int e1 = edge[i].second.first; int e2 = edge[i].second.second;
			if(merge(e1, e2)) {
				total += edge[i].first;
				cnt += 1;
			}
		}
		cout << totalcost - total << '\n';
	}
	return 0;
}

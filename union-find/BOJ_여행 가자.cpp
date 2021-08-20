#include <iostream>
#include <vector>
#define MAX 201
using namespace std;

int p[MAX];
vector<int> edge[MAX];

int find(int n) {
	if(p[n] < 0) return n;
	return find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(p[a] < p[b]) {
		p[a] += p[b];
		p[b] = a; // b의 부모 노드로 a 지정
	} else {
		p[b] += p[a];
		p[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, a, b, command;
	cin >> N >> M;
	for(int i = 1; i <= N; i++) p[i] = -1;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> a;
			if(a == 1 && (find(i) != find(j))) {
				merge(i, j);
			}
		}
	}
	cin >> a;
	int cur = find(a);
	for(int i = 1; i < M; i++) {
		cin >> a;
		if(cur != find(a)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

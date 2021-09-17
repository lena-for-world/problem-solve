#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;
int visit[1001];
vector<int> v[1001];

void dfs(int n) {
	visit[n] = 1;
	cout << n << " ";
	for(int i = 0; i < v[n].size(); i++) {
		if(!visit[v[n][i]]) {
			dfs(v[n][i]);
		}
	}
}

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	while(!q.empty()) {
		int f = q.front(); q.pop();
		cout << f << " ";
		for(int i = 0; i < v[f].size(); i++) {
			if(!visit[v[f][i]]) {
				visit[v[f][i]] = 1;
				q.push(v[f][i]);
			}
		}
	}
}

void init() {
	for(int i = 1; i <= N; i++) {
		visit[i] = 0;
	}
}

int main() {
	int a, b;
	cin >> N >> M >> V;
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	cout << '\n';
	init();
	bfs(V);
	return 0;
}

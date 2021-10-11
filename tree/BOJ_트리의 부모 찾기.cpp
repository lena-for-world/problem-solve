#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent;
vector<int> visit;
vector<vector<int>> nodes;

void makeTree() {
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	while(!q.empty()) {
		int t = q.front(); q.pop();
		for(int a : nodes[t]) {
			if(!visit[a]) {
				visit[a] = 1;
				parent[a] = t;
				q.push(a);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	parent.resize(n+1, -1);
	visit.resize(n+1, 0);
	nodes.resize(n+1);
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	makeTree();
	for(int i = 2; i<= n; i++) cout << parent[i] << '\n';
	return 0;
}

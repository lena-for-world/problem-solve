#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

int parent[10001];

int find(int node) {
	if(parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

bool same_union(int s, int e) {
	return find(s) == find(e);
}

void get_new_root(int s, int e) {
	int s1 = find(s);
	int s2 = find(e);
	if(s1 < s2) parent[s1] = s2;
	else parent[s2] = s1;
}

int main() {
	int v, e;
	int ans = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	cin >> v >> e;
	for(int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		parent[a] = a;
		parent[b] = b;
		pq.push({-c, {a,b}});
	}
	while(!pq.empty()) {
		pair<int, pair<int,int>> p = pq.top();
		int w = -p.first;
		int s = p.second.first, e = p.second.second;
		pq.pop();
		if(same_union(s, e)) {
			continue;
		} else {
			get_new_root(s, e);
			ans += w;
		}
	}
	cout << ans;
	return 0;
}

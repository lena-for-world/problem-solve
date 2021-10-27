#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct edge {
	int s, e, t;
};

int main() {
	int tc, n, m, w;
	cin >> tc;
	for(int i = 0; i < tc; i++) {
		bool flag = false;
		cin >> n >> m >> w;
		vector<edge> edges;
		vector<int> visit(n+1, INF);
		for(int j = 0; j < m; j++) {
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back({s,e,t});
			edges.push_back({e,s,t});
		}
		for(int j = 0; j < w; j++) {
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}
    /*
      이 부분을 지워도 정답 코드를 받음
      시작하는 지점이 어느 지점이더라도 상관없기 때문
      아래 코드를 그대로 둔다면 시작 지점이 0인 거고, 없앤다면 시작 지점이 INF가 된다는 차이만 존재
    */
		visit[1] = 0;
		for(int a = 1; a <= n-1; a++) {
			for(int j = 0; j < edges.size(); j++) {
				int s = edges[j].s, e = edges[j].e, w = edges[j].t;
				if(visit[e] > visit[s] + w) {
					visit[e] = visit[s] + w;
				}
			}
		}
		for(int j = 0; j < edges.size(); j++) {
				int s = edges[j].s, e = edges[j].e, w = edges[j].t;
				if(visit[e] > visit[s] + w) {
					flag = true;
				}
			}
		if(flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}

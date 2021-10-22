#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> e[20001];

int dijkstra(int a, int n) {
    int answer = -1, cnt = 0;
    vector<int> visit(n+1, 0);
    vector<vector<int>> path(n+1, vector<int>(n+1, 987654321));
    priority_queue<pair<int, int>> pq;
    visit[a] = 1;
    pq.push({0, a});
    while(!pq.empty()) {
        int now = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(int next : e[node]) {
            if(visit[next] == 0) {
                visit[next] = 1;
                if(path[node][next] > now + 1) {
                    path[node][next] = now + 1;
                    pq.push({-path[node][next], next});
                    answer = max(path[node][next], answer);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(answer == path[i][j]) cnt++;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    for(int i = 0; i < edge.size(); i++) {
        int a = edge[i][0], b = edge[i][1];
        e[a].push_back(b);
        e[b].push_back(a);
    }
    return dijkstra(1, n);
}

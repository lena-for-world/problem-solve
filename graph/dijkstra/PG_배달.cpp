#include <vector>
#include <queue>
using namespace std;

// 다익스트라

int solution(int n, vector<vector<int> > road, int k) {
    int answer = 0;
    vector<int> res(n+1, 987654321);
    vector<vector<int>> route(n+1, vector<int> (n+1, 10001));
    vector<int> edge[51];
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < road.size(); i++) {
        int start = road[i][0], end = road[i][1], w = road[i][2];
        if(route[start][end] > w) {
            route[start][end] = route[end][start] = w;
            edge[start].push_back(end);
            edge[end].push_back(start);
        }
    }
    res[1] = 0;
    pq.push({res[1], 1});
    while(!pq.empty()) {
        int now = pq.top().second, weight = -pq.top().first;
        pq.pop();
        for(int next : edge[now]) {
            if(res[next] > weight + route[now][next]) {
                res[next] = weight + route[next][now];
                pq.push({-res[next], next});
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if(res[i] <= k) answer++;
    }
    return answer + 1;
}

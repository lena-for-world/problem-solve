#include <string>
#include <vector>

using namespace std;

// 위상정렬인가? 싶어서 삽질 좀 함...

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> edge(n+1, vector<bool>(n+1, false));
    for(int i = 0; i < results.size(); i++) {
        edge[results[i][0]][results[i][1]] = true;
    }
    for(int i =1; i<= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(edge[j][i] && edge[i][k]) {
                    edge[j][k] = true;
                }
            }
        }
    }
    for(int i = 1; i<= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(edge[i][j] || edge[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    return answer;
}

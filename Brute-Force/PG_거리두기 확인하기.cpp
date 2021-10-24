#include <string>
#include <vector>

using namespace std;

int diry[4] = {0,0,-1,1};
int dirx[4] = {1,-1,0,0};
int visit[5][5];
bool res = true;

void dfs(int y, int x, int cnt, vector<string>& v) {
    if(cnt > 2 || v[y][x] == 'X') {
        return;
    }
    if(cnt != 0 && v[y][x] == 'P' && res == true) {
        res = false;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int t1 = y+diry[i], t2 = x + dirx[i];
        if(t1 < 0 || t1 >= v.size() || t2 < 0 || t2 >= v[0].size()) continue;
        if(!visit[t1][t2]) {
            visit[t1][t2] = 1;
            dfs(t1, t2, cnt+1, v);
            visit[t1][t2] = 0;
        }
    }
}

void init() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            visit[i][j] = 0;
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(places.size(), 1);
    for(int i = 0; i < places.size(); i++) {
        for(int j = 0; j < places[i].size(); j++) {
            for(int k = 0; k < places[i][j].size(); k++) {
                if(places[i][j][k] == 'P') {
                    init();
                    visit[j][k] = 1;
                    res = true;
                    dfs(j, k, 0, places[i]);
                    if(!res) answer[i] = 0;
                }
            }
        }
    }
    return answer;
}

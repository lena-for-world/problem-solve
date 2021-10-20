#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<pair<string, string>, int> check;
map<string, vector<string>> m;
vector<string> res;

void dfs(vector<string>& answer, string city, int total, int cnt) {
    if(total == cnt) {
        // m이 알파벳 순으로 초기화 되어있기 때문에
        // 맨 처음 cnt의 길이를 가진 경로가 답
        // 이후 cnt를 달성한 경로로 답이 초기화됨을 방지하기 위해서 if문 도입
        if(res.size() < answer.size()) res = answer;
        return;
    }
    for(int i = 0; i < m[city].size(); i++) {
        string temp = m[city][i];
        if(check[{city, temp}] != 0) {
            check[{city, temp}]--;
            answer.push_back(temp);
            //cout << answer.size() << endl;
            dfs(answer, temp, total, cnt+1);
            answer.erase(answer.end()-1);
            check[{city, temp}]++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int total = tickets.size()+1;
    vector<string> answer;
    for(int i = 0 ;i < tickets.size(); i++) {
        string s1, s2;
        s1 = tickets[i][0]; s2 = tickets[i][1];
        m[s1].push_back(s2);
        check[{s1,s2}]++;
        sort(m[s1].begin(), m[s1].end());
    }
    answer.push_back("ICN");
    dfs(answer, "ICN", total, 1);
    return res;
}

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;

void dfs(string line, char* members, vector<int>& visit, vector<string>& data) {
    if(line.size() == 8) {
        // 조건에 맞는지 확인 후 cnt++;
        bool flag = true;
        for(int i = 0; i < data.size(); i++) {
            char m1 = data[i][0], m2 = data[i][2], cond1 = data[i][3];
            int a, b, cond2 = data[i][4]-'0';
            for(int j = 0; j < 8; j++) {
                if(line[j] == m1) a = j;
                if(line[j] == m2) b = j;
            }
            if(cond1 == '=' && (abs(a-b) != cond2 + 1)) {
                flag = false;
            }
            else if(cond1 == '<' && (abs(a-b) > cond2)) {
                flag = false;
            }
            else if(cond1 == '>' && (abs(a-b) < cond2 + 2)) {
                flag = false;
            }
        }
        if(flag) answer++;
        return;
    }
    for(int i = 0; i < 8; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            // 줄 세우는 모든 경우는 8! 이고 조건은 최대 100가지
            // 따라서 모든 경우를 탐색goqhsek
            dfs(line + members[i], members, visit, data);
            visit[i] = 0;
        }
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    vector<int> visit(8, 0);
    char members[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    dfs("", members, visit, data);
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> cmv;
vector<string> candidate;

bool comp(string s1, string s2) {
    if(s1.size() == s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

void makeColumn(int cnt, int start, int mx, string st, int cn) {
    if(cnt == mx) {
        cmv.push_back(st);
        return;
    }
    for(int i = start+1; i < cn; i++) {
        char temp = i + 48;
        makeColumn(cnt+1, i, mx, st+temp, cn);
    }
}

bool isCandidate(string cmv) {
    for(int a = 0; a < candidate.size() ;a++) {
        int cnt = 0;
        for(int b = 0; b < cmv.size(); b++) {
            for(int c = 0; c < candidate[a].size(); c++) {
                if(cmv[b] == candidate[a][c]) cnt++;
                if(cnt == candidate[a].size()) return false;
            }
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    for(int j = 1; j <= relation[0].size(); j++) {
        for(int i = 0; i < relation[0].size(); i++) {
            string st = "";
            char c = i + 48;
            makeColumn(1, i, j, st+c, relation[0].size());
        }
    }
    sort(cmv.begin(), cmv.end(), comp);
    for(int i = 0; i < cmv.size(); i++) {
        int flag = 0;
        string st;
        map<string, int> m;
        for(int j = 0; j < relation.size(); j++) {
            st = "";
            for(int k = 0; k < cmv[i].size(); k++){
                st += relation[j][cmv[i][k]-48];
            }
            if(m[st]>0) {
                flag = 1;
                break;
            }
            m[st] = 1;
        }
        if(!flag) {
            // 후보키 중 겹치는 게 있는지 확인 후 아니라면
            if(isCandidate(cmv[i])) {
                answer++;
                candidate.push_back(cmv[i]);
            }
        }
    }
    return answer;
}

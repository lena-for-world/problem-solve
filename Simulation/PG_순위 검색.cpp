#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 들어오는 수가 크기 때문에 이중 for문 써서 탐색하면 시간 초과 발생 (최대 약 50초)
// 더 효율적인 방법을 찾아야 했던 문제

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> m;
    for(int i = 0; i < info.size(); i++) {
        string str = "", t1, t2, t3, t4;
        string st[4][2];
        istringstream iss(info[i]);
        iss >> st[0][0] >> st[1][0] >> st[2][0] >> st[3][0] >> str;
        st[0][1] = '-'; st[1][1] = '-'; st[2][1] = '-'; st[3][1] = '-'; 
        for(int a = 0; a < 2; a++) {
            t1 = st[0][a];
            for(int b = 0; b < 2; b++) {
                t2 = st[1][b];
                for(int c = 0; c< 2; c++) {
                    t3 = st[2][c];
                    for(int d = 0; d < 2; d++) {
                        t4 = st[3][d];
                        m[t1+t2+t3+t4].push_back(stoi(str));
                    }
                }
            }
        }
    }
    // lower_bound 사용 위해서
    for(auto it = m.begin(); it != m.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    for(int i = 0; i < query.size(); i++) {
        string str = "", st[4];
        int cnt = 0, score;
        
        istringstream iss(query[i]);
        iss >> st[0] >> str >> st[1] >> str >> st[2] >> str >> st[3] >> str;
        
        score = stoi(str);
        str = st[0] + st[1] + st[2] + st[3];
        
        auto iter = lower_bound(m[str].begin(), m[str].end(), score);
        cnt = m[str].size() - (iter - m[str].begin());
        answer.push_back(cnt);
    }
    return answer;
}

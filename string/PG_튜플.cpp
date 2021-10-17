#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    return s1.size() < s2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> temp;
    unordered_map<string, int> um;
    string num = "";
    for(int i = 1; i < s.size()-1; i++) {
        if(s[i] == '{') {
            continue;
        }
        if(s[i] == '}') {
            temp.push_back(num);
            num = "";
            i++;
            continue;
        }
        num += s[i];
    }
    sort(temp.begin(), temp.end(), cmp);
    for(int i = 0; i < temp.size(); i++) {
        string st = "";
        for(int j = 0; j < temp[i].size(); j++) {
                st += temp[i][j];
                if(temp[i][j+1] == ',' || j == temp[i].size()-1) {
                    int t = stoi(st);
                    if(um[st] == 0) {
                        answer.push_back(t);
                        um[st] = 1;
                    }
                    st = "";
                    j++;
                }
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int transNum(string a) {
    int ten = 1;
    int num = 0;
    for(int i = a.size()-1; i >= 0; i--) {
        num = (a[i]-'0') * ten + num;
        ten *= 10;
    }
    return num;
}

string makeUpper(string a) {
    string st = "";
    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= 97 && a[i] <= 122) {
            st = st + (char)(a[i]-32);
        } else {
            st += a[i];
        }
    }
    return st;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    map<string, vector<string>> m;
    vector<pair<int,string>> v;
    for(int i = 0; i < files.size(); i++) {
        int flag = 0;
        string st = "", head;
        string num = "";
        for(int j = 0; j < files[i].size(); j++) {
            if(flag == 0 && files[i][j] >= 48 && files[i][j] <= 57) {
                head = st;
                st = "";
                while(files[i][j] >= 48 && files[i][j] <= 57) {
                    num += files[i][j];
                    j++;
                }
                flag = 1;
                continue;
            }
            st += files[i][j];
        }
        v.push_back({transNum(num), makeUpper(head)});
        m[makeUpper(head)+to_string(transNum(num))].push_back(files[i]);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        string st = v[i].second+to_string(v[i].first);
        answer.push_back(m[st][0]);
        m[st].erase(m[st].begin());
    }
    return answer;
}

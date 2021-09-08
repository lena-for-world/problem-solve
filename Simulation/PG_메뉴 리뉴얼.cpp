#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<string, int> m;
vector<string> v;
priority_queue<pair<int, string>> pq;

void func(string order, int end, int len, int idx, string made) {
    if(len == end) {
        m[made] += 1;
        if(m[made] == 1) v.push_back(made);
        return;
    }
    for(int i = idx+1; i < order.size(); i++) {
        func(order, end, len+1, i, made+order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < course.size(); i++){
        for(int j = 0; j < orders.size(); j++) {
            sort(orders[j].begin(), orders[j].end());
            for(int k = 0; k < orders[j].size(); k++) {
                string made = "";
                func(orders[j], course[i], 1, k, made+orders[j][k]);
            }
        }
        for(int s = 0; s < v.size(); s++) {
            pq.push({m[v[s]], v[s]});
        }
        int t = 0;
        while(!pq.empty()) {
            t = pq.top().first;
            if(t > 1) {
                answer.push_back(pq.top().second);
                pq.pop();
            }
            break;
        }
        while(!pq.empty()) {
            if(t == pq.top().first && t > 1) {
                answer.push_back(pq.top().second);
                pq.pop();
            } else {
                while(!pq.empty()) pq.pop();
                break;
            }
        }
        v.clear();
        sort(answer.begin(), answer.end());
    }
    return answer;
}

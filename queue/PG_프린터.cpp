#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, cnt = 0;
    priority_queue<int> pq; // 중요도
    queue<pair<int, int>> q; // 중요도, 문서번호
    for(int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    while(!q.empty()) {
        int prior = pq.top();
        int now = q.front().first, nowsc = q.front().second;
        q.pop();
        if(prior <= now) {
            pq.pop();
            cnt++;
            if(nowsc == location) answer = cnt;
        } else {
            q.push({now, nowsc});
        }
    }
    return answer;
}

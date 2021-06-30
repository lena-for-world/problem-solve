#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++) pq.push(scoville[i]);
    // 위의 코드를 priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());로 쓰면 간단
    while(1) {
        long long t = 0;
        if(pq.size() == 1 && pq.top() < K) return -1;
        else if(pq.size() == 1 && pq.top() >= K) return answer;
        else if(pq.top() >= K) return answer;
        t = pq.top(); pq.pop();
        t = t + (pq.top() * 2); pq.pop();
        pq.push(t);
        answer++;
    }
}

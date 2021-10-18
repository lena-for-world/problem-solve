#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, idx = 0, total = 0;
    queue<int> q;
    int tracker[10001]; // 다리 위의 트럭이 어디쯤 달리고 있는지 파악
    while(1) {
        if(idx == truck_weights.size()) break;
        if(total + truck_weights[idx] <= weight) {
            q.push(idx);
            tracker[idx] = 0;
            total += truck_weights[idx];
            idx++;
        }
        int qsize = q.size();
        for(int i = 0; i < qsize; i++) {
            int t = q.front(); q.pop();
            if(++tracker[t] < bridge_length) {
                q.push(t);
            } else {
                total -= truck_weights[t];
            }
        }
        answer++;
    }
    return answer + bridge_length;
}

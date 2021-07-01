
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++) {
        q.push(i);
    }
    // 하나씩 더하는 방법 말고
    // ceil((double)(100 - progresses[i]) / (double)speeds[i])
    // 이렇게 몇 일 걸리는지 미리 계산해서 큐에 넣어주는 방법도 있었다
    // 훨씬 간단하다!!
    while(!q.empty()) {
        int cnt = 1;
        int f = q.front(); int j = q.front(); q.pop();
        while(j < progresses.size()) {
            progresses[j] += speeds[j];
            if(j == progresses.size()-1 && progresses[f] >= 100) break;
            if(j == progresses.size()-1) j = f;
            else j++;
        }
        while(!q.empty()) {
            int f = q.front();
            if(progresses[f] >= 100) {
                q.pop();
                cnt++;
            }
            else break;
        }
        answer.push_back(cnt);
    }
    return answer;
}


// O(N)의 더 

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue <int> q;
    for (int i = 0; i < progresses.size(); ++i)
        q.push(ceil((double)(100 - progresses[i]) / (double)speeds[i]));

    int num = 1;
    int cur = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() <= cur) {
            q.pop();
            ++num;
        }
        else {
            answer.push_back(num);
            num = 1;
            cur = q.front();
            q.pop();
        }
    }
    answer.push_back(num);

    return answer;
}

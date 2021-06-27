// 0 처리 주의할 것

bool cmp(pair<float, int> p1, pair<float, int> p2) {
    if(p1.first == p2.first) return p1.second <= p2.second;
    return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> v;
    int* temp= new int[N+1];
    for(int i = 1; i <= N; i++) temp[i] = 0;
    sort(stages.begin(), stages.end());
    for(int i = 0; i < stages.size(); i++) {
        if(stages[i] <= N) temp[stages[i]] += 1;
    }
    int prev = 0;
    int t = stages.size();
    for(int i = 1; i <= N; i++) {
        if(t-prev > 0) {
            v.push_back({(float)temp[i]/(t-prev), i});
            prev += temp[i];
        }
        else {
            if(temp[i] == 0) v.push_back({(float)0, i});
            else v.push_back({(float)temp[i]/temp[i], i});
            prev += temp[i];
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < N; i++) answer.push_back(v[i].second);
    return answer;
}

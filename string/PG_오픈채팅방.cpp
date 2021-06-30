vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> v;
    string st, st1, st2;
    map<string, int> room;
    map<string, string> id;
    for(int i = 0; i < record.size(); i++) {
        istringstream is(record[i]);
        is >> st;
        if(st == "Enter") {
            is >> st1 >> st2;
            id[st1] = st2;
            answer.push_back("님이 들어왔습니다.");
            v.push_back(st1);
        }
        if(st == "Leave") {
            is >> st1;
            answer.push_back("님이 나갔습니다.");
            v.push_back(st1);
        }
        if(st == "Change") {
            is >> st1 >> st2;
            id[st1] = st2;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        answer[i] = id[v[i]] + answer[i];
    }
    return answer;
}

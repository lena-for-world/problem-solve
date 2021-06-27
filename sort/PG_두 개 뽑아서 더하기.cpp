vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int> um;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i+1; j < numbers.size(); j++) {
            if(um[numbers[i]+numbers[j]] == 1) continue;
            um[numbers[i]+numbers[j]] = 1;
            answer.push_back(numbers[i]+numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}


// 다른 코드
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> st;
    for(int i = 0;i<numbers.size();++i){
        for(int j = i+1 ; j< numbers.size();++j){
            st.insert(numbers[i] + numbers[j]); // set은 중복을 허용하지 않고, 자동 정렬된다.
        }
    }
    answer.assign(st.begin(), st.end()); // answer에 st 할당 (+ assign은 기존 데이터 삭제)
    return answer;
}

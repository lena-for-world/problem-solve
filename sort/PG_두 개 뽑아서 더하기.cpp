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

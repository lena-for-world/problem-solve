vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> temp;
    temp = arr;
    sort(temp.begin(), temp.end());
    int t = temp[0];
    if(arr.size()==1) answer.push_back(-1);
    else {
        for(int i =0; i < arr.size(); i++)
            if(arr[i] != t) answer.push_back(arr[i]);
    }
    return answer;
}


vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int nmin = *min_element(arr.begin(), arr.end()); // algoritm 헤더
    int pos = find(answer.begin(), answer.end(), nmin) - answer.begin();
    answer.erase(answer.begin()+pos);
    return answer.size() == 0 ? vector<int>(1,-1) : answer;
}

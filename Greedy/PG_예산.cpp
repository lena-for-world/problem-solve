int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0, i = 0;
    sort(d.begin(), d.end());
    while(i < d.size() && sum + d[i] <= budget) {
        sum += d[i];
        i++;
    }
    answer = i;
    return answer;
}

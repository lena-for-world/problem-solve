vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int map[10001];
    for(int i = 1; i < 10001; i++) {
        map[i] = i;
    }
    for(int i = 0; i < queries.size(); i++) {
        int y1,y2,x1,x2;
        queue<int> idxq;
        queue<int> numq;
        y1 = queries[i][0]; y2 = queries[i][2]; x1 = queries[i][1]; x2 = queries[i][3];
        if(y1 > y2) {
            swap(y1,y2);
            swap(x1, x2);
        }
        for(int nx = x1; nx < x2; nx++) {
            numq.push(map[(y1-1)*columns+nx]);
            idxq.push((y1-1)*columns+nx);
        }
        for(int ny = y1; ny < y2; ny++) {
            numq.push(map[(ny-1)*columns+x2]);
            idxq.push((ny-1)*columns+x2);
        }
        for(int nx = x2; nx > x1; nx--) {
            numq.push(map[(y2-1)*columns+nx]);
            idxq.push((y2-1)*columns+nx);
        }
        for(int ny = y2; ny > y1; ny--) {
            numq.push(map[(ny-1)*columns+x1]);
            idxq.push((ny-1)*columns+x1);
        }
        int temp = idxq.front(); idxq.pop();
        int idx, num,res = 100000;
        while(!numq.empty()) {
            num = numq.front(); numq.pop();
            if(res > num) res = num;
            if(!idxq.empty()) { // 이 부분에 대한 처리를 안 해줘서 세그멘 에러가 났었음... 주의주의
                idx = idxq.front();
                idxq.pop();
                map[idx] = num;
            }
        }
        map[temp] = num;
        answer.push_back(res);
    }
    return answer;
}

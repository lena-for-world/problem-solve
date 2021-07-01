int my, nx;
int visit[101][101];

int search(int y, int x, vector<vector<int>> picture) {
    queue<pair<int, int>> q;
    int diry[4] = {1,-1,0,0};
    int dirx[4] = {0,0,-1,1};
    int cnt = 1;
    int col = picture[y][x];
    q.push({y,x});
    visit[y][x] = 1;
    while(!q.empty()) {
        pair<int, int> f = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int newy = f.first + diry[i]; int newx = f.second + dirx[i];
                if(newy < 0 || newy >= my || newx < 0 || newx >= nx) continue;
                if(!visit[newy][newx] && (picture[newy][newx] == col)){
                    q.push({newy, newx});
                    visit[newy][newx] = 1;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    my = m;
    nx = n;
    int acnt = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            visit[i][j] = 0;
        }
    }
    vector<int> answer(2, 0);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j]&& picture[i][j]==0) visit[i][j] = 1;
            if(!visit[i][j] && picture[i][j]!=0) {
                int temp = search(i,j, picture);
                acnt++;
                if(answer[1] < temp) {
                    answer[1] = temp;
                }
            }
        }
    }
    answer[0] = acnt;
    return answer;
}

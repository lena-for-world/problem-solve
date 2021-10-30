#include <iostream>
#include<vector>
using namespace std;

// 효율성 패스를 위해서 dp로 재작성

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    vector<vector<int>> v(board.size()+1, vector<int> (board[0].size()+1, 0));
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == 1) v[i][j] = 1;
        }
    }
    // 정사각형 한변의 길이가 2 미만이 될 수 밖에 없는 경우 아래의 for문이 실행되지 않으므로, 
    // if문에서 answer처리를 먼저 해줘야함
    if(board.size() < 2 || board[0].size() < 2) answer = v[0][0];
    for(int i = 1; i < board.size(); i++) {
        for(int j = 1; j < board[0].size(); j++) {
            if(board[i][j] == 1) {
                v[i][j] = min(v[i-1][j], min(v[i-1][j-1], v[i][j-1])) + 1;
                answer = max(answer, v[i][j]);
            }
        }
    }
    return answer*answer;
}


// bfs로 풀어서 효율성을 통과하지 못하는 코드
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirx[3] = {1, 0, 1};
int diry[3] = {0, 1, 1};
int visit[1001][1001];

int findSquare(pair<int, int> p, vector<vector<int>> board) {
    queue<pair<int, int>> q;
    q.push(p);
    int cnt = 1;
    visit[p.first][p.second] = 1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int a = 0; a < qsize; a++) {
            int y = q.front().first, x = q.front().second;
            q.pop();
            for(int i = 0 ; i < 3; i++) {
                int ny = y + diry[i], nx = x + dirx[i];
                if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) return cnt;
                if(board[ny][nx] != 1) return cnt;
                if(!visit[ny][nx]) {
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
        }
        cnt++;
    }
    return cnt;
}

void init() {
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            visit[i][j] = 0;
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int i = 0; i< board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 1) {
                init();
                answer = max(answer, findSquare({i, j}, board));
            }
        }
    }
    return answer * answer;
}

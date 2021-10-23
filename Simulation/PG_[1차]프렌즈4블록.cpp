#include <string>
#include <vector>

using namespace std;

// 칸들을 탐색, 현재 칸의 블럭을 기준으로 칸의 x+1 y+1, x+1, y+1 칸이 같은 지 체크하고
// 같다면 해당 칸들을 삭제 대상으로 놓음
// 위의 시행을 전체 칸에 대해 시행하고, 삭제 대상에 해당하는 칸들을 0으로 변경
// 전체 칸에 대해 빈칸만큼 아래로 땡겨줌
// 위의 시행을 반복
// 더 이상 삭제 대상이 된 칸이 없다면 종료

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int diry[4] = {0, 0, 1, 1};
    int dirx[4] = {0, 1, 0, 1};
    bool flag = true;
    while(flag) {
        flag = false;
        vector<pair<int, int>> rem;
        for(int i = 0; i < board.size()-1; i++) {
            for(int j = 0; j < board[i].size()-1; j++) {
                char temp = board[i][j];
                if(temp == '0') continue;
                if(temp == board[i+1][j] && temp == board[i][j+1] && temp == board[i+1][j+1]) {
                    flag = true;
                    for(int a = 0; a < 4; a++) {
                        rem.push_back({i+diry[a], j+dirx[a]});
                    }
                }
            }
        }
        for(int i = 0; i < rem.size(); i++) {
            int a = rem[i].first;
            int b = rem[i].second;
            if(board[a][b] != '0') {
                board[a][b] = '0';
                answer++;
            }
        }
        // 세로로 탐색
        for(int i = 0; i < board[0].size(); i++) {
            for(int j = board.size()-1; j >= 1; j--) {
                if(board[j][i] == '0') {
                    int idx = j;
                    while(idx > 0 && board[idx][i] == '0') {
                        idx--;
                    }
                    board[j][i] = board[idx][i];
                    board[idx][i] = '0';
                }
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s[30]; // 이거 안 만들어도 충분히 가능했다
    stack<int> ans;
    for(int i = 0; i < board.size(); i++) {
        for(int j = board[i].size()-1; j >= 0; j--) {
            if(board[j][i] != 0) s[i].push(board[j][i]);
        }
    }
    for(int i = 0; i < moves.size(); i++) {
        if(!s[moves[i]-1].empty()) {
            if(!ans.empty()) {
                if(ans.top() == s[moves[i]-1].top()) {
                    answer+=2;
                    s[moves[i]-1].pop();
                    ans.pop();
                }
                else {
                    ans.push(s[moves[i]-1].top());
                    s[moves[i]-1].pop();
                }
            }
            else {
                ans.push(s[moves[i]-1].top());
                s[moves[i]-1].pop();
            }
        }
        else continue;
    }
    return answer;
}




// 스택을 굳이 30개씩 안 만들어도 된다. board에 접근하는 방식으로 해결할 수 있다.
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int i=0;i<moves.size();i++)
    {
        int check = moves[i] - 1;
        for(int j=0;j<board.size();j++)
        {
            if(board[j][check] != 0)
            {
                if(!s.empty() && s.top() == board[j][check])
                {
                    s.pop();
                    answer += 2;
                }
                else
                    s.push(board[j][check]);
                board[j][check] = 0;
                break;
            }
        }
    }
    return answer;
}

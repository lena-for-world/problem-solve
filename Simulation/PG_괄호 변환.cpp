#include <string>
#include <vector>

using namespace std;

// 괄호 방향을 뒤집으라는 말을 오해해서 문자열 뒤집기 하고 있었고... 시간 겁나 잡아먹음
// 문제를 잘못 읽는 일이 없도록 해야겠다 빠르게 이해만 했어도 금방 풀렸을 문제

bool check(string temp) {
    int left = 0, right = 0;
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] == '(') left++;
        else right++;
        if(left < right) return false;
    }
    if(left == right) return true;
    else return false;
}

bool balance(string temp) {
    int left = 0, right = 0;
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] == '(') left++;
        else right++;
    }
    if(left==right) return true;
    else return false;
}

string makeBracket(string p) {
    string u = "", v = "";
    string answer = "";
    int flag = 0;
    if(p == "") return p;
    for(int i = 0; i < p.size(); i++) {
        u += p[i];
        if(balance(u)) {
            // u가 균형 잡혔으면 남은걸로 v 만들기
    	    if(p.size()-u.size() > 0) v = p.substr(u.size(), p.size()-u.size());
            break;
        }
    }
    // u가 올바른 문자열인지 체크
    if(check(u)) {
        answer += u;
        flag = 1;
    }
    // u가 올바른 괄호 문자열이면 v에 대해 재귀
    if(flag) {
        answer += makeBracket(v);
    } else {
        answer += '(';
        answer += makeBracket(v);
        answer += ')';
        u = u.substr(1, u.size()-2);
        for(int i = 0; i < u.size(); i++) {
            if(u[i]=='(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    return answer;
}

string solution(string p) {
    return makeBracket(p);
}

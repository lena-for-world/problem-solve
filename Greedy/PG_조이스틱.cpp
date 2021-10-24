#include <string>
#include <vector>

using namespace std;

// ※※ 그리디가 아닌 것 같음! 그리디로 풀어서 테스트 케이스는 모두 통과했는데, 테케에 없는 예외는 통과못함
// 예를 들면 "CANAAAAANAN"이라는 이름에 대해서 그리디로 이동하면 49지만, 완탐으로 이동하면 48이 나옴
// 아래의 코드는 그리디기 때문에 완탐으로 짜봐야할듯

int solution(string name) {
    int answer = 0;
    string st = "";
    for(int i = 0; i < name.size(); i++) {
        // 알파벳 업다운 횟수 계산
        answer += (name[i]-'A') < (26-(name[i]-'A')) ? (name[i]-'A') : (26-(name[i]-'A'));
        st += 'A';
    }
    st[0] = name[0];
    bool flag = true;
    int l = 0, r = 0, cnt = 0;
    // 가장 가까운 글자  항상 최소 이동 횟수가 된다
    while(1) {
        if(st[l%name.size()] == 'A' && name[l%name.size()] != 'A') {
            r = l = l%name.size();
            answer += cnt;
            cnt = 0;
            st[l] = name[l];
            continue;
        } else if(st[(r+name.size()) % name.size()] == 'A' && name[(r+name.size()) % name.size()] != 'A') {
            l = r = (r+name.size()) % name.size();
            answer += cnt;
            cnt = 0;
            st[r] = name[r];
            continue;
        } else {
            l++;
            r--;
        }
        if(cnt >= name.size()) break;
        cnt++;
    }
    return answer;
}

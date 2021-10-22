#include <string>
#include <vector>

using namespace std;

char list[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string makenum(int n, int target) {
    if(target / n == 0) {
        string t = "";
        t += list[target % n];
        return t;
    }
    return makenum(n, target / n) + list[target % n];
}

string solution(int n, int t, int m, int p) {
    string answer = "", temp = "";
    int cnt = 0;
    for(int i = 0; i <= t*m; i++) {
        temp += makenum(n, i);
    }
    for(int i = 0; i < temp.size(); i++) {
        if(cnt == t) break;
        if((i % m + 1) == p) {
            answer += temp[i];
            cnt++;
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int n, string st) {
    if(n / 2 == 0) return st;
    char temp = (n % 2) + '0';
    return toBinary(n/2, st + temp);
}

int solution(int n) {
    int answer = 0, one = 0, t = n + 1;
    string st = toBinary(n, "");
    reverse(st.begin(), st.end());
    for(int i = 0; i < st.size(); i++) {
        if(st[i] == '1') one++;
    }
    while(1) {
        int tempo = 0;
        string st = toBinary(t, "");
        for(int i = 0; i < st.size(); i++) {
            if(st[i] == '1') tempo++;
        }
        if(tempo == one) {
            answer = t;
            break;
        }
        t++;
    }
    return answer;
}

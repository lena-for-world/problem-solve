#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 987654321;
    for(double i = 1; i <= s.size()/2+1; i++) {
        vector<string> v;
        string temp = ""; int cnt = 1; string last ="";
        for(int j = 0; j < s.size(); j += i) {
            v.push_back(s.substr(j, i));
        }
        for(int j = 1; j < v.size(); j++) {
            if(v[j] != v[j-1]) {
                if(cnt != 1) {
                    if(cnt >= 10) temp += to_string(cnt); // 숫자가 일의 자리를 넘어가는 경우에 대한 처리가 필요함
                    else temp += (cnt+'0');
                }
                last = v[j-1];
                temp += v[j-1];
                cnt = 1;
            }
            else cnt++;
        }
        if(last != v[v.size()-1]) {
            if(cnt != 1) {
                if(cnt >= 10) temp += to_string(cnt);
                else temp += (cnt+'0');
            }
            temp += v[v.size()-1];
        }
        int ssize = temp.size();
        answer = min(ssize, answer);
    }
    return answer;
}

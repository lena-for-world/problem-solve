#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> ssplit(string s, string div) {
    vector<string> v;
    istringstream iss(s);
    string s2;
    while(getline(iss, s2, ' ')) v.push_back(s2);
    return v;
}

string solution(string s) {
    string answer = "";
    vector<string> arr = ssplit(s, " ");
    for(int i = 0; i < arr.size(); i++) {
        string s = arr[i];
        for(int j = 0; j < s.size(); j++) {
            if(j == 0) {
                if(s[j] >= 97 && s[j] <= 122) s[j] -=32;
            } else {
                if(s[j] >= 65 && s[j] <= 90) s[j] += 32;
            }
        }
        answer += s;
        if(i + 1 == arr.size()) continue;
        else answer += ' ';
    }
    if(s[s.size()-1] == ' ') answer += ' '; // 맨 끝의 공백이 생략될 수도 있는 예외 고려
    return answer;
}

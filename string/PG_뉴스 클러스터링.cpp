#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> makeParts(string str1) {
    vector<string> v;
    for(int i = 0; i < str1.size()-1; i++) {
        string st = "";
        if((str1[i+1]-65) < 0 || (str1[i+1]-65) > 25) continue;
        if((str1[i]-65) < 0 || (str1[i]-65) > 25) continue;
        st += str1[i];
        st += str1[i+1];
        v.push_back(st);
    }
    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    double inter=0, uni=0;
    vector<string> v1, v2, t1, t2;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    v1 = t1 = makeParts(str1);
    v2 = t2 = makeParts(str2);
    // 교집합
    for(int i = 0 ; i < v1.size(); i++) {
        for(int j = 0 ; j < t2.size(); j++) {
            if(v1[i] == t2[j]) {
                inter++;
                t2.erase(t2.begin() + j);
                break;
            }
        }
    }
    //합집합
    for(int i = 0; i < v2.size(); i++) {
        for(int j = 0; j < t1.size(); j++) {
            if(v2[i] == t1[j]) {
                t1.erase(t1.begin() + j);
                break;
            }
        }
    }
    uni += v2.size();
    uni += t1.size();
    if(inter == 0 && uni ==0) answer = 65536;
    else answer = (int)((inter/uni) * 65536);
    return answer;
}

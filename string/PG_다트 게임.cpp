#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> cuts;
    int prev = 0, i = 0;
    while(i < dartResult.size()) {
        char res = dartResult[i];
        if(strchr("STD", res)) {
            char temp = dartResult[i+1];
            if(strchr("*#", temp)) {
                cuts.push_back(dartResult.substr(prev, (i+2)-prev)); // 시작주소, 자를 문자열의 길이
                prev = i+2;
                i = prev;
            }
            else {
                cuts.push_back(dartResult.substr(prev, (i+1)-prev));
                prev = i+1;
                i = prev;
            }
        }
        else i++;
    }
    vector<int> sum;
    for(int i = 0; i < cuts.size(); i++) {
        string num = "";
        int inum = 0;
        for(int j = 0; j < cuts[i].size(); j++) {
            if(cuts[i][j] =='S') {
                for(int q= 0; q < j; q++) num += cuts[i][q];
                inum = stoi(num);
            }
            else if(cuts[i][j] == 'D') {
                for(int q= 0; q < j; q++) num += cuts[i][q];
                inum = pow(stoi(num), 2);
            }
            else if(cuts[i][j] == 'T') {
                for(int q= 0; q < j; q++) num += cuts[i][q];
                inum = pow(stoi(num), 3);
            }
            if(cuts[i][j] == '#') inum *= -1;
            if(cuts[i][j] == '*') {
                inum *= 2;
                if(i-1 >= 0) sum[i-1] *= 2;
            }
        }
        sum.push_back(inum);
    }
    for(int i = 0; i < sum.size(); i++) answer += sum[i];
    return answer;
}




// 간단한 코드

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    vector<int> v;
    for(int i = 0, s = 0; i < dartResult.size(); ++i) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
            s = s * 10 + dartResult[i] - '0';
        else if(dartResult[i] == 'S') v.push_back(s), s = 0;
        else if(dartResult[i] == 'D') v.push_back(s * s), s = 0;
        else if(dartResult[i] == 'T') v.push_back(s * s * s), s = 0;
        else if(dartResult[i] == '*') {
            if(v.size() > 1) v.back() *= 2, v[v.size() - 2] *= 2;
            else v.back() *= 2;
        } else v.back() = -v.back();

    }
    int ans = 0;
    for(int i = 0; i < v.size(); ++i) ans += v[i];
    return ans;
}

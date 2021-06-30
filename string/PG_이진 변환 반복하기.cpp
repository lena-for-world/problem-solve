
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s_to_int(int s) {
    string st ="";
    while(s>1) {
        int temp = s % 2;
        s /= 2;
        st += (temp+'0');
    }
    st += (s+'0');
    return st;
}

vector<int> solution(string s) {
    vector<int> answer;
    int len = s.size();
    int cntz = 0, cntt = 0;
    while(len != 1) {
        for(int i = 0; i < s.size(); i++) if(s[i] == '0') cntz++;
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        int z = s.size();
        string nst = s_to_int(z);
        len = nst.size();
        s = nst;
        cntt++;
    }
    answer.push_back(cntt);
    answer.push_back(cntz);
    return answer;
}

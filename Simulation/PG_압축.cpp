#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    int dicSize = 26;
    for(int i = 0; i < 26; i++) {
        string a = "";
        a += ('A' + i);
        dic[a] = i+1;
    }
    int i = 0;
    while(i < msg.size()) {
        string findNow = "";
        findNow += msg[i];
        int j = i+1;
        string temp = findNow;
        while(1) {
            temp += msg[j];
            if(dic[temp] == 0) {
                dic[temp] = ++dicSize;
                temp.erase(temp.end()-1);
                answer.push_back(dic[temp]);
                i += temp.size();
                break;
            }
            j++;
        }
    }
    return answer;
}

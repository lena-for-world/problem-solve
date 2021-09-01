#include <string>
#include <vector>
#include <map>

using namespace std;

int duplicateTest(vector<string> words) {
    map<string, int> m;
    for(int i = 0; i< words.size(); i++) {
        string st = words[i];
        if(m[st] == 0) {
            m[st] = 1;
        } else return i;
    }
    return 0;
}

vector<int> duplicateCheck(vector<string> words, int cnt, int n) {
    vector<int> answer;
    int dup = duplicateTest(words);
    if(cnt != 0) {
        if(!dup) {
            answer.push_back(cnt%n+1);
            answer.push_back(cnt/n+1);
        } else {
            answer.push_back(dup%n+1);
            answer.push_back(dup/n+1);
        }
    } else {
        if(!dup) {
            answer.push_back(0);
            answer.push_back(0);
        } else {
            answer.push_back(dup%n+1);
            answer.push_back(dup/n+1);
        }
    }
    return answer;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int cnt = 0;
    string prev;
    for(int i = 0; i < words.size(); i++ ){
        if(i == 0) {
            prev = words[i];
        } else {
            if(prev[prev.size()-1] != words[i][0]) {
                cnt = i;
                break;
            } else {
                prev = words[i];
            }
        }
    }
    return duplicateCheck(words, cnt, n);
}

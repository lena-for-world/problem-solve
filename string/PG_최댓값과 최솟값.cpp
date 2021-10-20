#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string st = "";
    vector<int> num;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            num.push_back(stoi(st));
            st = "";
            continue;
        }
        st += s[i];
    }
    num.push_back(stoi(st));
    sort(num.begin(), num.end());
    return to_string(num[0]) + ' ' + to_string(num[num.size()-1]);
}

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool cmp(string st1, string st2) {
    if(st1[N] == st2[N]) return st1 < st2;
    return st1[N] < st2[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    vector<string> answer;
    sort(strings.begin(), strings.end(), cmp);
    answer = strings;
    return answer;
}

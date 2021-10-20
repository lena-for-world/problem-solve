#include <string>
#include <vector>

using namespace std;

int answer = 1000;

void dfs(string begin, string target, vector<string> words, vector<int>& check, int cnt) {
    
    if(begin == target) {
        answer = min(answer, cnt);
        return;
    }
    
    for(int i = 0; i < words.size(); i++) {
        int diff = 0;
        if(check[i]) continue; // 같은 단어 재탐색 방지
        for(int j = 0; j < words[i].size(); j++) {
            if(begin[j] != words[i][j]) diff++;
        }
        if(diff == 1) {
            check[i] = 1;
            dfs(words[i], target, words, check, cnt + 1);
            check[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<int> check(words.size(), 0);
    dfs(begin, target, words, check, 0);
    return answer == 1000 ? 0 : answer;
}

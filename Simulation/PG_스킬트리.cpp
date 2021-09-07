#include <string>
#include <vector>
#include <map>

using namespace std;

// 위상정렬 문제인가 싶었는데 그렇게 안 해도 되겠더라
// map으로 각 스킬의 단계를 저장해서 풀었다

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;
    for(int i = 0; i < skill.size(); i++) {
        m[skill[i]] = i+1;
    }
    for(int i = 0;i < skill_trees.size(); i++) {
        int basis = 0;
        int flag = 1;
        for(int j = 0; j < skill_trees[i].size(); j++) {
            char sk = skill_trees[i][j];
            if(m[sk] == 0) {
                continue;
            } else {
                if(m[sk] == basis+1) { 
                    basis = m[sk];
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) answer++;
    }
    return answer;
}

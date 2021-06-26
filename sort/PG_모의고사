#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> ans;
    int one = 0, two = 0, three = 0;
    int n1[5] = {1,2,3,4,5};
    int n2[8] = {2,1,2,3,2,4,2,5};
    int n3[10] = {3,3,1,1,2,2,4,4,5,5};
    for(int i = 0; i < answers.size(); i++) {
        if(n1[i%5] == answers[i]) one++;
        if(n2[i%8] == answers[i]) two++;
        if(n3[i%10] == answers[i]) three++;
    }
    ans.push_back({one, 1}); ans.push_back({two, 2}); ans.push_back({three, 3});
    sort(ans.begin(), ans.end());
    for(int i = 0; i< 3; i++) {
        if(ans[i].first == ans[2].first) {
            answer.push_back(ans[i].second);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

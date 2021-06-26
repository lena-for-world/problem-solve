#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0, zero = 0;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    for(int i = lottos.size()-1; i >= 0; i--) {
        if(lottos[i] == 0) zero++;
        for(int j = win_nums.size(); j >= 0; j--) {
            if(lottos[i] == win_nums[j]) cnt++;
        }
    }
    
    if((cnt+zero) > 1 && (cnt+zero) < 6) answer.push_back((6-(cnt+zero))+1);
    else if((cnt+zero) == 6) answer.push_back(1);
    else answer.push_back(6);
    
    if(cnt > 1 && cnt < 6) answer.push_back(6-cnt+1);
    else if(cnt == 6) answer.push_back(1);
    else answer.push_back(6);
    return answer;
}

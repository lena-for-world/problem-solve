#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    int i = 0;
    int tsum = 0;
    sort(nums.begin(), nums.end());
    while(i < nums.size()) {
        auto l = lower_bound(nums.begin(), nums.end(), nums[i]);
        auto u = upper_bound(nums.begin(), nums.end(), nums[i]);
        tsum++;
        i += u-l;
    }
    if(tsum > N/2) answer = N/2;
    else answer = tsum;
    return answer;
}



// 다른 사람의 풀이

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}

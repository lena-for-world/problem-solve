#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int prime[3003];

int solution(vector<int> nums) {
    int answer = 0;
    memset(prime, 0 ,sizeof(prime));
    sort(nums.begin(), nums.end());
    prime[0] = 1, prime[1] = 1;
    for(int i = 2; i < 3003; i++) {
        for(int j = i * i; j < 3003; j+=i) {
            prime[j] = 1;
        }
    }
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            for(int q = j+1; q < nums.size(); q++) {
                if(prime[nums[i]+nums[j]+nums[q]] == 0) answer++;
            }
        }
    }
    return answer;
}


// 소수를 미리 만들어 둘 필요 없이, 그 때 그 때 만든 합을 소수 판별 할 수도 있음
bool check(int n){
    for(int i=2;i<n/2;i++)
        if(n%i==0)
            return false;
    return true;
}

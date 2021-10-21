#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int source = 1;
    vector<unordered_set<int>> dp(9);
    dp[1].insert(N);
    // for문 들어가면 N을 2개 사용하는 경우부터 체크하기 때문에
    // N과 number가 같은 경우 1을 리턴하는 if문을 작성함
    if(N == number) return 1;
    for(int i = 2; i < 9; i++) {
        source = source * 10 + 1;
        for(int j = 1; j < i; j++) {
            for(int k = 1; k < i; k++) {
                if(j + k != i) continue;
                for(int a : dp[j]) {
                    for(int b : dp[k]) {
                        dp[i].insert(a+b);
                        dp[i].insert(a*b);
                        if(a-b > 0) dp[i].insert(a-b);
                        if(a / b > 0) dp[i].insert(a / b);
                    }
                }
            }
            dp[i].insert(N*source);
        }
        if(dp[i].count(number))
            return i;
    }
    return -1;
}

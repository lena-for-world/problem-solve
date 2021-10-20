#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[100001];

int fibo(int n) {
    if(dp[n]) return dp[n];
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    dp[n] = fibo(n-1) % 1234567 + fibo(n-2) % 1234567;
    return dp[n] % 1234567;
}

int solution(int n) {
    memset(dp, 0, sizeof(dp));
    return fibo(n);
}

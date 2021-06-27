#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int* prime = new int[1000001];
    memset(prime, 0, sizeof(prime));
    for(int i = 2; i <= sqrt(1000000); i++) {
        for(int j = i*i; j <= 1000000; j += i) {
            prime[j] = 1;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(prime[i] == 0) answer++;
    }
    return answer;
}

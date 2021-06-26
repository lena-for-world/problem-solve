#include <string>
#include <vector>

using namespace std;

int measure(int n) {
    int cnt = 0;
    for(int i = n; i > 0; i--) {
        if(n % i == 0) cnt++;
    }
    return cnt % 2;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++) {
        if(measure(i)) answer -= i;
        else answer += i;
    }
    return answer;
}

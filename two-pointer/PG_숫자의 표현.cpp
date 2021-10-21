#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 1, j = 1, sum = 0;
    while(j <= i) {
        if(sum + i >= n) {
            if(sum + i == n) answer++;
            sum -= j++;
            continue;
        }
        else sum += i++;
    }
    return answer;
}

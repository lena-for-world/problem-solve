#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    int temp = 0;
    while(n != 0) {
        temp = n % 3;
        if(temp == 0) {
            n = n/3 - 1; // 귀납적으로 얻어냈어야 하는 부분으로 보임
            answer += '4';
        }
        else {
            n /= 3;
            answer += (temp+'0');
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string water = "수";
    string watermelon = "수박";
    for(int i =2; i <= n; i +=2) {
        answer += watermelon;
    }
    if(n%2) answer += water;
    return answer;
}


// 내 코드보다 훨씬 간단하고 좋은 비트연산자 코드
// 홀수는 항상 비트 맨끝자리가 ...1 이라는 점을 이용

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for(int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";

    return answer;
}

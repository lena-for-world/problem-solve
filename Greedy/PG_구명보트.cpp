#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, idx = 0, sum = 0;
    sort(people.begin(), people.end());
    int i = 0, j = people.size()-1;
    while(i <= j) {
        // 둘만 탈 수 있는 구명보트
        if(people[i] + people[j]  > limit) {
            j--;
        } else {
            i++;
            j--;
        }
        answer++;
    }
    return answer;
}

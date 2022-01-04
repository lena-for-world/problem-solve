#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0, i = 0, j = 0;
    sort(numbers.begin(), numbers.end());
    while(i < 10) {
        if(j >= numbers.size()) {
            answer += i++;
            continue;
        }
        if(i < numbers[j]) {
            answer += i++;
            continue;
        } 
        i++;
        j++;
    }
    return answer;
}

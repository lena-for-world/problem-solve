#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> temp(n+1, 0);
    for(int i = 0; i < lost.size(); i++) {
        temp[lost[i]] = -1;
    }
    for(int i = 0; i < reserve.size(); i++) {
        temp[reserve[i]] += 1;
    }
    for(int i = 1; i <= n; i++) {
        if(i+1 <= n && temp[i] == -1 && temp[i+1] == 1) {
            temp[i+1] -= 1;
            temp[i] += 1;
        }
        else if(i-1 > 0 && temp[i] == -1 && temp[i-1] == 1) {
            temp[i-1] -= 1;
            temp[i] += 1;
        }
    }
    for(int i = 1; i <= n; i++) cout << temp[i] << " ";
    for(int i =1; i <= n; i++) {
        if(temp[i] == 0 || temp[i] == 1) answer++;
    }
    return answer;
}

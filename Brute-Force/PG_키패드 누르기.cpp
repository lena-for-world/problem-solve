#include <string>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left ={3,0}, right={3,2}, now;
    for(int i = 0; i < numbers.size(); i++) {
        int temp = numbers[i];
        if(temp == 0) temp = 11;
        int tempy = (temp -1) / 3;
        int tempx = (temp -1) % 3;
        now = {tempy, tempx};
        if(temp == 1 || temp == 4 || temp == 7) {
            left = now;
            answer += 'L';
        }
        else if(temp == 3 || temp == 6 || temp == 9) {
            right = now;
            answer += 'R';
        }
        else {
            int lsum = abs((left.first) - (now.first)) + abs((left.second) - (now.second));
            int rsum = abs((right.first) - (now.first)) + abs((right.second) - (now.second)); 
            if(lsum == rsum) {
                if(hand == "right") {
                    answer += 'R';
                    right = now;
                }
                else {
                    answer += 'L';
                    left = now;
                }
            }
            else {
                if(lsum > rsum) {
                    answer += 'R';
                    right = now;
                }
                else {
                    answer += 'L';
                    left = now;
                }
            }
        }
    }
    return answer;
}

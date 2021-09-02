

/**
* 바텀업 방식
* 바텀업으로 해야 시간 초과를 방지할 수 있었다
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int j = 0; j < land.size(); j++) {
        if(j+1 == land.size()) break;
        land[j+1][3] = max(land[j][0], max(land[j][1], land[j][2])) + land[j+1][3];
        land[j+1][2] = max(land[j][0], max(land[j][1], land[j][3])) + land[j+1][2];
        land[j+1][1] = max(land[j][0], max(land[j][3], land[j][2])) + land[j+1][1];
        land[j+1][0] = max(land[j][3], max(land[j][1], land[j][2])) + land[j+1][0];
    }
    int n = land.size()-1;
    answer = max(land[n][0], max(land[n][1], max(land[n][2], land[n][3])));
    return answer;
}


/**
* 이건 탑다운 코드인데 시간 초과가 발생했다
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

int dp[MAX][4];
int answer;

int search(vector<vector<int>> land, int row, int col) {
    if(row == land.size()-1) return land[row][col];
    if(dp[row][col] != 0) return dp[row][col];
    int temp = 0;
    for(int i = 0; i < 4; i++) {
        if(col == i) {
            continue;
        }
        temp = max(temp, search(land, row+1, i));
    }
    return dp[row][col] = temp + land[row][col];
}

int solution(vector<vector<int> > land)
{
    answer = 0;
    // 전역변수 초기화
    for(int i = 0;i < MAX; i++) {
        for(int j = 0; j < 4; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i = 0;i < 4; i++) {
        answer = max(answer, search(land, 0, i));
    }
    return answer;
}

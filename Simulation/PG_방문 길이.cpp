#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int visit[11][11][4];
    int nowy = 5, nowx = 5, ny, nx, d1, d2;
    for(int i = 0; i < 11; i++) {
        for(int j = 0 ; j < 11 ; j++){
            for(int k = 0; k < 4; k++)
                visit[i][j][k] = 0;
        }
    }
    // U == 0, D == 1, L == 2, R == 3
    for(int i = 0; i < dirs.size(); i++) {
        char dir = dirs[i];
        if(dir == 'U') {
            ny = nowy+1, nx = nowx; d1 = 0, d2 = 1;
            if(ny >= 11) continue;
        } else if(dir == 'D') {
            ny = nowy-1, nx = nowx;
            d1 = 1, d2 = 0;
            if(ny < 0) continue;
        } else if(dir == 'L') {
            ny = nowy, nx = nowx-1;
            d1 = 2, d2 = 3;
            if(nx < 0) continue;
        } else {
            ny = nowy, nx = nowx+1;
            d1 = 3, d2 = 2;
            if(nx >= 11) continue;
        }
        if(!visit[ny][nx][d2] && !visit[nowy][nowx][d1]) {
            visit[ny][nx][d2] = visit[nowy][nowx][d1] = 1;
            answer++;
        }
        nowy = ny, nowx = nx;
    }
    return answer;
}

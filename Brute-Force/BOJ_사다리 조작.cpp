#include <iostream>
using namespace std;

bool lad[30][11];
int res = -1;
int N, H;
int goal;
bool flag = false;

void dfs(int i, int cnt) {
	// 세로줄은 N까지, 가로줄은 H까지, 개수는 3개까지 (출구조건)
	if(flag) return;
	// 3개 이하로 선택한 경우 사다리 게임을 시행해서 i번의 결과가
	// i번인지 확인하고 가능하다면 res가 최소인 경우 저장한다
	if(cnt == goal) {
		bool avail = true;
		for(int a = 1; a <= N; a++) {
			int row = a;
			for(int b = 1; b <= H; b++) {
				if(lad[b][row]) row++;
				else if(row > 1 && lad[b][row-1]) {
					row--;
				}
			}
			if(row != a) {
				avail = false;
				break;
			}
		}
		if(avail) {
			flag = true;
		}
		return;
	}
	for(int a = i; a <= H; a++) {
		for(int b = 1; b < N; b++) {
			// 이전 세로줄에서 같은 가로줄을 이용했으면 건너뜀
			if(!lad[a][b] && !lad[a][b-1] && !lad[a][b+1]) {
				lad[a][b] = 1;
				dfs(a, cnt+1);
				lad[a][b] = 0;
			}
		}
	}
	return;
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M, a, b;
	cin >> N >> M >> H;
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		lad[a][b] = true;
	}
  // 가능한 개수만큼 확인함
  // 가장 먼저 구해지는 가능한 경우가 최소의 조작 횟수가 됨
	for(int i = 0; i <= 3; i++) {
		goal = i;
		dfs(1, 0);
		if(flag) {
			cout << goal;
			return 0;
		}
	}
	cout << res;
	return 0;
}

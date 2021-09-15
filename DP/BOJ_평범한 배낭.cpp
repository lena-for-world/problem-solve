#include <iostream>
using namespace std;

int n, k;
int weight[101], value[101];
int bag[100001][101];

// idx번째 물건을 넣었거나 넣지 않았을 경우의 무게를 체크하고 저장한다
int dfs(int w, int idx) {
	if(idx > n) return 0;
	if(bag[w][idx] != -1) return bag[w][idx];
	int temp = 0;
  // idx번째 물건을 넣었을 때
	if(w + weight[idx] <= k) temp = dfs(w+weight[idx], idx+1)+value[idx];
  // idx번째 물건을 넣지 않았을 때
	bag[w][idx] = max(temp, dfs(w, idx+1));
	return bag[w][idx];
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= n; j++)
			bag[i][j] = -1;
	cout << dfs(0,0);
	return 0;
}

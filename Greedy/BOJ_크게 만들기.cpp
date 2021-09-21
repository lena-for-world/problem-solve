#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, k, i = 0, cnt = 0;
	string st;
	cin >> n >> k >> st;
	stack<int> prestack, ans;
	while(1) {
		if(i == st.size()) break;
		if(cnt == k) break;
		int num = st[i] -'0';
		while(!prestack.empty()) {
			int temp = prestack.top();
      // 이전 수보다 현재 수가 더 크다면 이전 수를 제거한다
			if(temp < num) {
				prestack.pop();
				cnt++;
			} else {
				break;
			}
			if(cnt == k) break;
		}
		prestack.push(num);
		i++;
	}
  // k개를 제거하지 못하고 탐색이 끝났다면 맨 끝에서부터 남은 k만큼 제거한다
  // 작은 수부터 제거되므로 항상 성립한다
	while(cnt < k) {
		prestack.pop();
		cnt++;
	}
  // 정답을 옮겨담는다
	while(!prestack.empty()) {
		ans.push(prestack.top());
		prestack.pop();
	}
	while(!ans.empty()) {
		cout << ans.top();
		ans.pop();
  }
  // 탐색되지 못한 남은 문자가 있다면 출력
	if(i != st.size()-1) cout << st.substr(i, st.size()-i);
	return 0;
}

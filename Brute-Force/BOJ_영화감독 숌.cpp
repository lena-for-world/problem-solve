#include <iostream>
using namespace std;

// 6이 연속으로 3개 나오는 경우일 때만 개수를 더하면서 n번째 답이 구해질 때까지 모든 수를 살펴봄

int main() {
	int n, cnt = 0, num = 666;
	cin >> n;
	while(1) {
		int six = 0;
		string st= to_string(num);
		for(int i = 1; i < st.size(); i++) {
			if(st[i] == '6' && st[i-1] == '6') six++;
			else {
				if(six >= 2) continue;
				else six = 0;
			}
		}
		if(six >= 2) {
			cnt++;
		}
		if(cnt == n) {
			cout << num;
			break;
		}
		num++;
	}
	return 0;
}

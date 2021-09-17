#include <iostream>
using namespace std;

int main() {
  // 1부터 더해가면서 사용한 수의 개수 증가
  // 합이 s를 넘는 순간 합과 s의 차만큼 빼주면 s를 만들 수 있으므로 (사용한 수 -1)이 답
	long long s, temp, num = 1, cnt = 0;
	cin >> s;
	while(temp != s) {
		if(temp > s) {
			temp -= (temp - s);
			cnt--;
		} else {
			temp += num;
			cnt++;
			num++;
		}
	}
	cout << cnt;
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	string exprs = "";
	int flag = 0;
	cin >> exprs;
	int num = 0, sum = 0;
	for(int i = 0; i < exprs.size(); i++) {
		if(exprs[i] -'0' >= 0 && exprs[i] - '0' <= 9) {
			num = (exprs[i]-'0') + (num*10);
		}
		else if(exprs[i] == '+') {
			// 앞에 -가 나온적없음
			if(!flag) sum += num;
			else sum -= num;
			num = 0;
		}
		else {
			// 앞에 -가 나온적 있음
			if(flag) sum -= num;
			else {
				flag = 1;
				sum += num;
			}
			num = 0;
		}
	}
	if(flag && num > 0) sum -= num;
	else sum += num;
	cout << sum;
	return 0;
}

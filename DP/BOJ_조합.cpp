#include <iostream>
using namespace std;

int n, m;
string dp[101][101];

// long long 형을 넘어가는 경우가 존재하기 때문에
// string으로 계산
string bigIntegerCalc(string a, string b) {
	string st = "";
	int carry = 0; // 각 자리의 수를 더했을 경우 10이 넘어가면 carry에 1 저장
	char c;
	for(int i = a.size()-1; i >= 0; i--) {
		int num1 = a[i]-'0';
		int num2 = b[i]-'0';
		if(num1 + num2 + carry >= 10) {
			num1 = num1 + num2 - 10 + carry;
			carry = 1;
		} else {
			num1 = num1 + num2 + carry;
			carry = 0;
		}
		c = num1 + '0';
		st = c + st;
	}
	if(carry == 1) st = "1" + st;
	return st;
}


string calc(int a, int b) {
	if(a < 0 || b < 0) return "0";
	if(a == 0 || b == 0) return "1";
	if(a == b) return "1";
	string& ret = dp[a][b];
	if(ret != "-") return ret;
	string st1 = calc(a-1, b);
	string st2 = calc(a-1, b-1);
	if(st1.size() < st2.size()) {
		string temp = "";
		for(long long a = 0;a < st2.size()-st1.size(); a++) {
			temp += "0";
		}
		temp += st1;
		st1 = temp;
	} else {
		string temp = "";
		for(long long a = 0;a < st1.size()-st2.size(); a++) {
			temp += "0";
		}
		temp += st2;
		st2 = temp;
	}
	ret = bigIntegerCalc(st1, st2);
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < 101; i++) {
		for(int j = 0; j < 101; j++) {
			dp[i][j] = "-";
		}
	}
	cout << calc(n, m);
	return 0;
}

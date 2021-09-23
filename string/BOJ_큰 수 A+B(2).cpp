#include <iostream>
using namespace std;

string n, m;

// big integer 계산
string bigIntegerCalc(string a, string b) {
	string st = "";
	int carry = 0;
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

// 길이 짧은 문자열의 앞자리를 padding 0으로 채우기
string makeSameSize(string st1, string st2) {
	string temp = "";
	for(long long a = 0; a < st2.size()-st1.size(); a++) {
		temp += "0";
	}
	temp += st1;
	return temp;
}

int main() {
	cin >> n >> m;
	if(n.size() < m.size()) {
		n = makeSameSize(n, m);
	} else {
		m = makeSameSize(m, n);
	}
	cout << bigIntegerCalc(n, m);
	return 0;
}
